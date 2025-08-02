#pragma once

#include "Events/ApplicationEvent.h"

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
        /// 事件回调函数
        /// </summary>
        /// <param name="e">事件</param>
        void OnEvent(Event& event);

        /// <summary>
        /// 运行：主循环
        /// </summary>
        void Run();

        /// <summary>
        /// 关闭
        /// </summary>
        void Close();

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

        bool m_Running = true;      // 运行状态
        bool m_Minimized = false;   // 窗口最小化
    };

    /// <summary>
    /// 创建 App：在 LuckyApplication 中定义
    /// </summary>
    /// <returns></returns>
    Application* CreateApplication();
}