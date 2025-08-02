#include "lcpch.h"
#include "Application.h"

namespace LuckyEngine
{
    Application* Application::s_Instance = nullptr;

    Application::Application()
    {
        LC_CORE_ASSERT(!s_Instance, "Application 已存在!");

        s_Instance = this;

        m_Window = Window::Create(WindowProps());                               // 创建窗口
        m_Window->SetEventCallback(LC_BIND_EVENT_FUNC(Application::OnEvent));   // 设置回调函数
    }

    Application::~Application()
    {

    }

    void Application::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);  // 事件调度器
        dispatcher.Dispatch<WindowCloseEvent>(LC_BIND_EVENT_FUNC(Application::OnWindowClose));      // 窗口关闭事件
        dispatcher.Dispatch<WindowResizeEvent>(LC_BIND_EVENT_FUNC(Application::OnWindowResize));    // 窗口大小改变事
    }

    void Application::Run()
    {
        while (m_Running)
        {
            m_Window->OnUpdate();   // 更新窗口
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