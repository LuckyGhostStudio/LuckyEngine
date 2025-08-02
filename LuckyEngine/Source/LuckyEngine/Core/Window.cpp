#include "lcpch.h"
#include "Window.h"

#include "LuckyEngine/Core/Events/ApplicationEvent.h"
#include "LuckyEngine/Core/Events/KeyEvent.h"
#include "LuckyEngine/Core/Events/MouseEvent.h"

#include "LuckyEngine/Utils/ConvertUtility.h"

#ifndef GET_X_LPARAM
#define GET_X_LPARAM(lParam) ((int)(short)LOWORD(lParam))
#endif

#ifndef GET_Y_LPARAM
#define GET_Y_LPARAM(lParam) ((int)(short)HIWORD(lParam))
#endif

namespace LuckyEngine
{
    Scope<Window> Window::Create(const WindowProps& props)
    {
        return CreateScope<Window>(props);
    }

    Window::Window(const WindowProps& props)
    {
        Init(props);
    }

    Window::~Window()
    {
        Shutdown();
    }

    void Window::Init(const WindowProps& props)
    {
        m_Data.Title = props.Title;
        m_Data.Width = props.Width;
        m_Data.Height = props.Height;

        LC_CORE_INFO("Creating window " + props.Title + " (", props.Width, ",", props.Height, ")");

        // 创建 EasyX 图形窗口
        initgraph((int)props.Width, (int)props.Height);
        m_Window = GetHWnd();

        // 修改窗口样式为可调整大小
        LONG style = GetWindowLong(m_Window, GWL_STYLE);
        style |= WS_THICKFRAME | WS_MAXIMIZEBOX | WS_MINIMIZEBOX;
        SetWindowLong(m_Window, GWL_STYLE, style);

        // 设置窗口标题
        SetWindowText(m_Window, ConvertUtility::StringToWString(m_Data.Title).c_str());

        m_Context = EasyXContext::Create(m_Window); // 创建 EasyX 上下文
        m_Context->Init();                          // 初始化上下文

        // 子类化窗口
        m_OriginalWndProc = reinterpret_cast<WNDPROC>(SetWindowLongPtr(m_Window, GWLP_WNDPROC,reinterpret_cast<LONG_PTR>(Window::WndProc)));

        // 将窗口实例与句柄关联
        SetProp(m_Window, L"WindowInstance", this);
    }

    LRESULT Window::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        // 获取窗口实例
        Window* window = static_cast<Window*>(GetProp(hWnd, L"WindowInstance"));

        // 先处理自定义事件
        if (window)
        {
            window->ProcessMessage(uMsg, wParam, lParam);
        }

        // 调用原始窗口过程
        return CallWindowProc(window ? window->m_OriginalWndProc : nullptr, hWnd, uMsg, wParam, lParam);
    }

    void Window::ProcessMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        switch (uMsg)
        {
            // 窗口关闭
            case WM_CLOSE:
            {
                WindowCloseEvent event;     // 窗口关闭事件
                m_Data.EventCallback(event);
                break;
            }
            // 窗口大小改变
            case WM_SIZE:
            {
                // 窗口更新后大小
                int width = LOWORD(lParam);
                int height = HIWORD(lParam);

                m_Data.Width = width;
                m_Data.Height = height;

                WindowResizeEvent event(width, height); // 创建窗口大小改变事件
                m_Data.EventCallback(event);
                break;
            }
            // 键盘按键按下
            case WM_KEYDOWN:
            {
                KeyPressedEvent event((int)wParam, false);   // 按键按下事件
                m_Data.EventCallback(event);
                break;
            }
            // 键盘按键抬起
            case WM_KEYUP:
            {
                KeyReleasedEvent event((int)wParam);     // 按键抬起事件
                m_Data.EventCallback(event);
                break;
            }
            // 鼠标按下事件
            case WM_LBUTTONDOWN:
            {
                MouseButtonPressedEvent event(WM_LBUTTONDOWN);  // 左键
                m_Data.EventCallback(event);
                break;
            }
            case WM_MBUTTONDOWN:
            {
                MouseButtonPressedEvent event(WM_MBUTTONDOWN);  // 中键
                m_Data.EventCallback(event);
                break;
            }
            case WM_RBUTTONDOWN:
            {
                MouseButtonPressedEvent event(WM_RBUTTONDOWN);  // 右键
                m_Data.EventCallback(event);
                break;
            }
            // 鼠标抬起事件
            case WM_LBUTTONUP:
            {
                MouseButtonReleasedEvent event(WM_LBUTTONUP);   // 左键
                m_Data.EventCallback(event);
                break;
            }
            case WM_MBUTTONUP:
            {
                MouseButtonReleasedEvent event(WM_MBUTTONUP);   // 中键
                m_Data.EventCallback(event);
                break;
            }
            case WM_RBUTTONUP:
            {
                MouseButtonReleasedEvent event(WM_RBUTTONUP);   // 右键
                m_Data.EventCallback(event);
                break;
            }
            // 鼠标滚轮事件
            case WM_MOUSEWHEEL:
            {
                int yOffset = GET_WHEEL_DELTA_WPARAM(wParam) / WHEEL_DELTA; // 滚轮滚动值 + 向上滚动 - 向下滚动
                MouseScrolledEvent event(0, (float)yOffset);    // 鼠标滚轮滚动事件
                m_Data.EventCallback(event);
                break;
            }
            // 鼠标移动事件
            case WM_MOUSEMOVE:
            {
                int x = GET_X_LPARAM(lParam);
                int y = GET_Y_LPARAM(lParam);
                MouseMovedEvent event((float)x, (float)y);  // 鼠标移动事件
                m_Data.EventCallback(event);
                break;
            }
        }
    }

    void Window::Shutdown()
    {
        // 移除关联并恢复原始窗口过程
        RemoveProp(m_Window, L"WindowInstance");
        SetWindowLongPtr(m_Window, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(m_OriginalWndProc));

        EndBatchDraw(); // 关闭后缓冲区渲染模式
        closegraph();   // 关闭图形窗口
    }

    void Window::OnUpdate()
    {
        // 处理消息
        MSG msg;
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
            {
                Shutdown(); // 关闭窗口
                return;
            }

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        m_Context->SwapBuffers();   // 交换前后缓冲区
    }
}