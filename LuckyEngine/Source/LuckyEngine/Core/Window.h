#pragma once

#include <graphics.h>

#include "LuckyEngine/Core/Base.h"
#include "LuckyEngine/Core/Events/Event.h"
#include "LuckyEngine/Core/EasyXContext.h"

namespace LuckyEngine
{
    /// <summary>
    /// ��������
    /// </summary>
    struct WindowProps
    {
        std::string Title;      // ����
        unsigned int Width;     // ��
        unsigned int Height;    // ��

        WindowProps(const std::string& title = "LuckyEngine", unsigned int width = 1280, unsigned int height = 720)
            : Title(title), Width(width), Height(height)
        {

        }
    };

    /// <summary>
    /// ������
    /// </summary>
    class Window
    {
    public:
        using EventCallbackFn = std::function<void(Event&)>;    // �¼��ص����� void func(Event&)

        /// <summary>
        /// ��������
        /// </summary>
        /// <param name="props">��������</param>
        /// <returns>����</returns>
        static Scope<Window> Create(const WindowProps& props = WindowProps());

        /// <summary>
        /// ����
        /// </summary>
        /// <param name="props">��������</param>
        Window(const WindowProps& props);

        virtual ~Window();

        /// <summary>
        /// ���£�ÿ֡����
        /// </summary>
        void OnUpdate();

        inline unsigned int GetWidth() const { return m_Data.Width; }
        inline unsigned int GetHeight() const { return m_Data.Height; }

        /// <summary>
        /// �����¼��ص���������Application����
        /// </summary>
        /// <param name="callback">�ص�����</param>
        inline void SetEventCallback(const EventCallbackFn& callback) { m_Data.EventCallback = callback; }

        /// <summary>
        /// ���� GLFW ����
        /// </summary>
        /// <returns>����ָ��</returns>
        virtual void* GetNativeWindow() const { return m_Window; }
    private:
        /// <summary>
        /// ��ʼ������
        /// </summary>
        /// <param name="props">��������</param>
        virtual void Init(const WindowProps& props);

        /// <summary>
        /// ������Ϣ������
        /// </summary>
        /// <param name="hWnd"></param>
        /// <param name="uMsg"></param>
        /// <param name="wParam"></param>
        /// <param name="lParam"></param>
        /// <returns></returns>
        static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

        /// <summary>
        /// ������Ϣ
        /// </summary>
        /// <param name="uMsg"></param>
        /// <param name="wParam"></param>
        /// <param name="lParam"></param>
        virtual void ProcessMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

        /// <summary>
        /// �رմ���
        /// </summary>
        virtual void Shutdown();
    private:
        HWND m_Window;                  // EasyX ����
        WNDPROC m_OriginalWndProc;      // ԭʼ���ڹ��̺���
        Scope<EasyXContext> m_Context;  // EasyX ������

        /// <summary>
        /// ��������
        /// </summary>
        struct WindowData
        {
            std::string Title;      // ����
            unsigned int Width;     // ��
            unsigned int Height;    // ��

            EventCallbackFn EventCallback;  // �¼��ص�����
        };

        WindowData m_Data;  // ��������
    };
}