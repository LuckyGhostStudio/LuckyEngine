#pragma once

#include "Window.h"
#include "Events/ApplicationEvent.h"
#include "LayerStack.h"

namespace LuckyEngine
{
    /// <summary>
    /// 应用程序：管理应用程序的入口点和生命周期
    /// </summary>
    class Application
    {
    public:
        Application();
        virtual ~Application();

        /// <summary>
        /// 添加普通层到层栈
        /// </summary>
        /// <param name="layer">普通层</param>
        void PushLayer(Layer* layer) { m_LayerStack.PushLayer(layer); }

        /// <summary>
        /// 添加覆盖层到层栈
        /// </summary>
        /// <param name="layer">覆盖层</param>
        void PushOverlay(Layer* layer) { m_LayerStack.PushOverlay(layer); }

        /// <summary>
        /// 从层栈移除普通层
        /// </summary>
        /// <param name="layer">普通层</param>
        void PopLayer(Layer* layer) { m_LayerStack.PopLayer(layer); }

        /// <summary>
        /// 从层栈移除覆盖层
        /// </summary>
        /// <param name="layer">覆盖层</param>
        void PopOverlay(Layer* layer) { m_LayerStack.PopOverlay(layer); }

        /// <summary>
        /// 事件回调函数
        /// </summary>
        /// <param name="e">事件</param>
        void OnEvent(Event& e);

        /// <summary>
        /// 运行：主循环
        /// </summary>
        void Run();

        /// <summary>
        /// 关闭
        /// </summary>
        void Close();

        Window& GetWindow() { return *m_Window; }
        static Application& GetInstance() { return *s_Instance; }
    private:
        /// <summary>
        /// 窗口关闭回调函数
        /// </summary>
        /// <param name="e">窗口关闭事件</param>
        /// <returns>是否已关闭</returns>
        bool OnWindowClose(WindowCloseEvent& e);

        /// <summary>
        /// 窗口缩放时调用
        /// </summary>
        /// <param name="e">窗口缩放事件</param>
        /// <returns>事件处理结果</returns>
        bool OnWindowResize(WindowResizeEvent& e);
    private:
        static Application* s_Instance;

        Scope<Window> m_Window;     // 窗口
        LayerStack m_LayerStack;    // 层栈

        bool m_Running = true;      // 运行状态
        bool m_Minimized = false;   // 窗口最小化
    };

    /// <summary>
    /// 创建 App：在 LuckyApplication 中定义
    /// </summary>
    /// <returns></returns>
    Application* CreateApplication();
}