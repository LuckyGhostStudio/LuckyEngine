#pragma once

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
        /// 运行：主循环
        /// </summary>
        void Run();

        /// <summary>
        /// 关闭
        /// </summary>
        void Close();

        static Application& GetInstance() { return *s_Instance; }
    private:
        static Application* s_Instance;

        bool m_Running = true;  // 运行状态
    };

    /// <summary>
    /// 创建 App：在 LuckyApplication 中定义
    /// </summary>
    /// <returns></returns>
    Application* CreateApplication();
}