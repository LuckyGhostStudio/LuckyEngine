#include "lcpch.h"
#include "Application.h"

namespace LuckyEngine
{
    Application* Application::s_Instance = nullptr;

    Application::Application()
    {
        LC_CORE_ASSERT(!s_Instance, "Application �Ѵ���!");

        s_Instance = this;
    }

    Application::~Application()
    {

    }

    void Application::OnEvent(Event& event)
    {
        EventDispatcher dispatcher(event);  // �¼�������
        dispatcher.Dispatch<WindowCloseEvent>(LC_BIND_EVENT_FUNC(Application::OnWindowClose));      // ���ڹر��¼�
        dispatcher.Dispatch<WindowResizeEvent>(LC_BIND_EVENT_FUNC(Application::OnWindowResize));    // ���ڴ�С�ı���
    }

    void Application::Run()
    {
        while (m_Running)
        {
            
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