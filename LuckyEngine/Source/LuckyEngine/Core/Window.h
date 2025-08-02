#pragma once

#include <graphics.h>

#include "LuckyEngine/Core/Base.h"
#include "LuckyEngine/Core/Events/Event.h"
#include "LuckyEngine/Core/EasyXContext.h"

namespace LuckyEngine
{
    /// <summary>
    /// 窗口属性
    /// </summary>
    struct WindowProps
    {
        std::string Title;      // 标题
        unsigned int Width;     // 宽
        unsigned int Height;    // 高

        WindowProps(const std::string& title = "LuckyEngine", unsigned int width = 1280, unsigned int height = 720)
            : Title(title), Width(width), Height(height)
        {

        }
    };

    /// <summary>
    /// 窗口类
    /// </summary>
    class Window
    {
    public:
        using EventCallbackFn = std::function<void(Event&)>;    // 事件回调函数 void func(Event&)

        /// <summary>
        /// 创建窗口
        /// </summary>
        /// <param name="props">窗口属性</param>
        /// <returns>窗口</returns>
        static Scope<Window> Create(const WindowProps& props = WindowProps());

        /// <summary>
        /// 窗口
        /// </summary>
        /// <param name="props">窗口属性</param>
        Window(const WindowProps& props);

        virtual ~Window();

        /// <summary>
        /// 更新：每帧调用
        /// </summary>
        void OnUpdate();

        inline unsigned int GetWidth() const { return m_Data.Width; }
        inline unsigned int GetHeight() const { return m_Data.Height; }

        /// <summary>
        /// 设置事件回调函数：从Application设置
        /// </summary>
        /// <param name="callback">回调函数</param>
        inline void SetEventCallback(const EventCallbackFn& callback) { m_Data.EventCallback = callback; }

        /// <summary>
        /// 返回 GLFW 窗口
        /// </summary>
        /// <returns>窗口指针</returns>
        virtual void* GetNativeWindow() const { return m_Window; }
    private:
        /// <summary>
        /// 初始化窗口
        /// </summary>
        /// <param name="props">窗口属性</param>
        virtual void Init(const WindowProps& props);

        /// <summary>
        /// 窗口消息处理函数
        /// </summary>
        /// <param name="hWnd"></param>
        /// <param name="uMsg"></param>
        /// <param name="wParam"></param>
        /// <param name="lParam"></param>
        /// <returns></returns>
        static LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

        /// <summary>
        /// 处理消息
        /// </summary>
        /// <param name="uMsg"></param>
        /// <param name="wParam"></param>
        /// <param name="lParam"></param>
        virtual void ProcessMessage(UINT uMsg, WPARAM wParam, LPARAM lParam);

        /// <summary>
        /// 关闭窗口
        /// </summary>
        virtual void Shutdown();
    private:
        HWND m_Window;                  // EasyX 窗口
        WNDPROC m_OriginalWndProc;      // 原始窗口过程函数
        Scope<EasyXContext> m_Context;  // EasyX 上下文

        /// <summary>
        /// 窗口数据
        /// </summary>
        struct WindowData
        {
            std::string Title;      // 标题
            unsigned int Width;     // 宽
            unsigned int Height;    // 高

            EventCallbackFn EventCallback;  // 事件回调函数
        };

        WindowData m_Data;  // 窗口数据
    };
}