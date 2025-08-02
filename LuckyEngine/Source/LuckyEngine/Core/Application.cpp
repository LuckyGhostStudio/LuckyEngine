#include "lcpch.h"
#include "Application.h"

namespace LuckyEngine
{
    Application* Application::s_Instance = nullptr;

    Application::Application()
    {
        LC_CORE_ASSERT(!s_Instance, "Application �Ѵ���!");

        s_Instance = this;

        m_Window = Window::Create(WindowProps());                               // ��������
        m_Window->SetEventCallback(LC_BIND_EVENT_FUNC(Application::OnEvent));   // ���ûص�����
    }

    Application::~Application()
    {

    }

    void Application::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);  // �¼�������
        dispatcher.Dispatch<WindowCloseEvent>(LC_BIND_EVENT_FUNC(Application::OnWindowClose));      // ���ڹر��¼�
        dispatcher.Dispatch<WindowResizeEvent>(LC_BIND_EVENT_FUNC(Application::OnWindowResize));    // ���ڴ�С�ı���
    }

    void Application::Run()
    {
        while (m_Running)
        {
            m_Window->OnUpdate();   // ���´���
        }
    }

    void Application::Close()
    {
        m_Running = false;
    }
    bool Application::OnWindowClose(WindowCloseEvent& e)
    {
        m_Running = false;  // ��������
        return true;
    }

    bool Application::OnWindowResize(WindowResizeEvent& e)
    {
        if (e.GetWidth() == 0 || e.GetHeight() == 0)
        {
            m_Minimized = true; // ������С��
            return false;
        }

        m_Minimized = false;

        return false;
    }
}