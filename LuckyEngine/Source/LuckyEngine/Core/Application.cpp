#include "lcpch.h"
#include "Application.h"

#include "Input/Input.h"
#include "Events/KeyEvent.h"
#include "LuckyEngine/Renderer/Renderer.h"
#include "LuckyEngine/Renderer/Renderer2D.h"
#include "LuckyEngine/Utils/CriticalSection.h"

namespace LuckyEngine
{
    Application* Application::s_Instance = nullptr;

    Application::Application()
    {
        LC_CORE_ASSERT(!s_Instance, "Application �Ѵ���!");

        s_Instance = this;

        m_Window = Window::Create(WindowProps());                               // ��������
        m_Window->SetEventCallback(LC_BIND_EVENT_FUNC(Application::OnEvent));   // ���ûص�����

        CriticalSection::Init();    // ��ʼ���ٽ���
        Renderer::Init();           // ��ʼ����Ⱦ��
    }

    Application::~Application()
    {

    }

    void Application::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);  // �¼�������
        dispatcher.Dispatch<WindowCloseEvent>(LC_BIND_EVENT_FUNC(Application::OnWindowClose));      // ���ڹر��¼�
        dispatcher.Dispatch<WindowResizeEvent>(LC_BIND_EVENT_FUNC(Application::OnWindowResize));    // ���ڴ�С�ı���

        LC_CORE_INFO(e.ToString());

        // ��������±�����ջ
        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
        {
            if (e.m_Handled)
            {
                break;  // �¼��Ѵ���
            }
            (*--it)->OnEvent(e);    // ���ȡ�������¼�
        }
    }

    void Application::Run()
    {
        while (m_Running)
        {
            {
                CriticalSection::Lock lock;   // RAII����ȷ���̰߳�ȫ

                RenderCommand::SetClearColor(RGB(111, 111, 111));
                RenderCommand::Clear();

                Renderer2D::BeginScene();

                Renderer2D::DrawRect(100, 100, 100, 100);

                Renderer2D::EndScene();
            }

            // ����δ��С��
            if (!m_Minimized)
            {
                // ���²�ջ�����в�
                for (Layer* layer : m_LayerStack)
                {
                    layer->OnUpdate();
                }
            }

            m_Window->OnUpdate();   // ���´���
        }
    }

    void Application::Close()
    {
        Renderer::Shutdown();           // �ر���Ⱦ��
        CriticalSection::Shutdown();    // �ر��ٽ���

        m_Running = false;
    }

    bool Application::OnWindowClose(WindowCloseEvent& e)
    {
        m_Running = false;  // ��������
        return true;
    }

    bool Application::OnWindowResize(WindowResizeEvent& e)
    {
        CriticalSection::Lock lock;   // RAII����ȷ���̰߳�ȫ

        int width = e.GetWidth();   // ��
        int height = e.GetHeight(); // ��

        if (width == 0 || height == 0)
        {
            m_Minimized = true; // ������С��
            return false;
        }

        Renderer::OnWindowResize(width, height);    // ������Ⱦ���ӿڴ�С

        m_Minimized = false;

        return false;
    }
}