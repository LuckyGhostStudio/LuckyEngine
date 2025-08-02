#include "lcpch.h"
#include "Application.h"

namespace LuckyEngine
{
    Application* Application::s_Instance = nullptr;

    Application::Application()
    {
        LC_CORE_ASSERT(!s_Instance, "Application 已存在!");

        s_Instance = this;
    }

    Application::~Application()
    {

    }

    void Application::OnEvent(Event& event)
    {
        EventDispatcher dispatcher(event);  // 事件调度器
        dispatcher.Dispatch<WindowCloseEvent>(LC_BIND_EVENT_FUNC(Application::OnWindowClose));      // 窗口关闭事件
        dispatcher.Dispatch<WindowResizeEvent>(LC_BIND_EVENT_FUNC(Application::OnWindowResize));    // 窗口大小改变事
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
        m_Running = false;  // 结束运行
        return true;
    }

    bool Application::OnWindowResize(WindowResizeEvent& e)
    {
        if (e.GetWidth() == 0 || e.GetHeight() == 0)
        {
            m_Minimized = true; // 窗口最小化
            return false;
        }

        m_Minimized = false;

        return false;
    }
}