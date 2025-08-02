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

        // ���� EasyX ͼ�δ���
        initgraph((int)props.Width, (int)props.Height);
        m_Window = GetHWnd();

        // �޸Ĵ�����ʽΪ�ɵ�����С
        LONG style = GetWindowLong(m_Window, GWL_STYLE);
        style |= WS_THICKFRAME | WS_MAXIMIZEBOX | WS_MINIMIZEBOX;
        SetWindowLong(m_Window, GWL_STYLE, style);

        // ���ô��ڱ���
        SetWindowText(m_Window, ConvertUtility::StringToWString(m_Data.Title).c_str());

        m_Context = EasyXContext::Create(m_Window); // ���� EasyX ������
        m_Context->Init();                          // ��ʼ��������

        // ���໯����
        m_OriginalWndProc = reinterpret_cast<WNDPROC>(SetWindowLongPtr(m_Window, GWLP_WNDPROC,reinterpret_cast<LONG_PTR>(Window::WndProc)));

        // ������ʵ����������
        SetProp(m_Window, L"WindowInstance", this);
    }

    LRESULT Window::WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        // ��ȡ����ʵ��
        Window* window = static_cast<Window*>(GetProp(hWnd, L"WindowInstance"));

        // �ȴ����Զ����¼�
        if (window)
        {
            window->ProcessMessage(uMsg, wParam, lParam);
        }

        // ����ԭʼ���ڹ���
        return CallWindowProc(window ? window->m_OriginalWndProc : nullptr, hWnd, uMsg, wParam, lParam);
    }

    void Window::ProcessMessage(UINT uMsg, WPARAM wParam, LPARAM lParam)
    {
        switch (uMsg)
        {
            // ���ڹر�
            case WM_CLOSE:
            {
                WindowCloseEvent event;     // ���ڹر��¼�
                m_Data.EventCallback(event);
                break;
            }
            // ���ڴ�С�ı�
            case WM_SIZE:
            {
                // ���ڸ��º��С
                int width = LOWORD(lParam);
                int height = HIWORD(lParam);

                m_Data.Width = width;
                m_Data.Height = height;

                WindowResizeEvent event(width, height); // �������ڴ�С�ı��¼�
                m_Data.EventCallback(event);
                break;
            }
            // ���̰�������
            case WM_KEYDOWN:
            {
                KeyPressedEvent event((int)wParam, false);   // ���������¼�
                m_Data.EventCallback(event);
                break;
            }
            // ���̰���̧��
            case WM_KEYUP:
            {
                KeyReleasedEvent event((int)wParam);     // ����̧���¼�
                m_Data.EventCallback(event);
                break;
            }
            // ��갴���¼�
            case WM_LBUTTONDOWN:
            {
                MouseButtonPressedEvent event(WM_LBUTTONDOWN);  // ���
                m_Data.EventCallback(event);
                break;
            }
            case WM_MBUTTONDOWN:
            {
                MouseButtonPressedEvent event(WM_MBUTTONDOWN);  // �м�
                m_Data.EventCallback(event);
                break;
            }
            case WM_RBUTTONDOWN:
            {
                MouseButtonPressedEvent event(WM_RBUTTONDOWN);  // �Ҽ�
                m_Data.EventCallback(event);
                break;
            }
            // ���̧���¼�
            case WM_LBUTTONUP:
            {
                MouseButtonReleasedEvent event(WM_LBUTTONUP);   // ���
                m_Data.EventCallback(event);
                break;
            }
            case WM_MBUTTONUP:
            {
                MouseButtonReleasedEvent event(WM_MBUTTONUP);   // �м�
                m_Data.EventCallback(event);
                break;
            }
            case WM_RBUTTONUP:
            {
                MouseButtonReleasedEvent event(WM_RBUTTONUP);   // �Ҽ�
                m_Data.EventCallback(event);
                break;
            }
            // �������¼�
            case WM_MOUSEWHEEL:
            {
                int yOffset = GET_WHEEL_DELTA_WPARAM(wParam) / WHEEL_DELTA; // ���ֹ���ֵ + ���Ϲ��� - ���¹���
                MouseScrolledEvent event(0, (float)yOffset);    // �����ֹ����¼�
                m_Data.EventCallback(event);
                break;
            }
            // ����ƶ��¼�
            case WM_MOUSEMOVE:
            {
                int x = GET_X_LPARAM(lParam);
                int y = GET_Y_LPARAM(lParam);
                MouseMovedEvent event((float)x, (float)y);  // ����ƶ��¼�
                m_Data.EventCallback(event);
                break;
            }
        }
    }

    void Window::Shutdown()
    {
        // �Ƴ��������ָ�ԭʼ���ڹ���
        RemoveProp(m_Window, L"WindowInstance");
        SetWindowLongPtr(m_Window, GWLP_WNDPROC, reinterpret_cast<LONG_PTR>(m_OriginalWndProc));

        EndBatchDraw(); // �رպ󻺳�����Ⱦģʽ
        closegraph();   // �ر�ͼ�δ���
    }

    void Window::OnUpdate()
    {
        // ������Ϣ
        MSG msg;
        while (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE))
        {
            if (msg.message == WM_QUIT)
            {
                Shutdown(); // �رմ���
                return;
            }

            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }

        m_Context->SwapBuffers();   // ����ǰ�󻺳���
    }
}