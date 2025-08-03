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
        LC_CORE_ASSERT(!s_Instance, "Application 已存在!");

        s_Instance = this;

        m_Window = Window::Create(WindowProps());                               // 创建窗口
        m_Window->SetEventCallback(LC_BIND_EVENT_FUNC(Application::OnEvent));   // 设置回调函数

        CriticalSection::Init();    // 初始化临界区
        Renderer::Init();           // 初始化渲染器
    }

    Application::~Application()
    {

    }

    void Application::OnEvent(Event& e)
    {
        EventDispatcher dispatcher(e);  // 事件调度器
        dispatcher.Dispatch<WindowCloseEvent>(LC_BIND_EVENT_FUNC(Application::OnWindowClose));      // 窗口关闭事件
        dispatcher.Dispatch<WindowResizeEvent>(LC_BIND_EVENT_FUNC(Application::OnWindowResize));    // 窗口大小改变事

        LC_CORE_INFO(e.ToString());

        // 从最顶层向下遍历层栈
        for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();)
        {
            if (e.m_Handled)
            {
                break;  // 事件已处理
            }
            (*--it)->OnEvent(e);    // 层获取并处理事件
        }
    }

    void Application::Run()
    {
        while (m_Running)
        {
            {
                CriticalSection::Lock lock;   // RAII锁，确保线程安全

                RenderCommand::SetClearColor(RGB(111, 111, 111));
                RenderCommand::Clear();

                Renderer2D::BeginScene();

                Renderer2D::DrawRect(100, 100, 100, 100);

                Renderer2D::EndScene();
            }

            // 窗口未最小化
            if (!m_Minimized)
            {
                // 更新层栈中所有层
                for (Layer* layer : m_LayerStack)
                {
                    layer->OnUpdate();
                }
            }

            m_Window->OnUpdate();   // 更新窗口
        }
    }

    void Application::Close()
    {
        Renderer::Shutdown();           // 关闭渲染器
        CriticalSection::Shutdown();    // 关闭临界区

        m_Running = false;
    }

    bool Application::OnWindowClose(WindowCloseEvent& e)
    {
        m_Running = false;  // 结束运行
        return true;
    }

    bool Application::OnWindowResize(WindowResizeEvent& e)
    {
        CriticalSection::Lock lock;   // RAII锁，确保线程安全

        int width = e.GetWidth();   // 宽
        int height = e.GetHeight(); // 高

        if (width == 0 || height == 0)
        {
            m_Minimized = true; // 窗口最小化
            return false;
        }

        Renderer::OnWindowResize(width, height);    // 调整渲染器视口大小

        m_Minimized = false;

        return false;
    }
}