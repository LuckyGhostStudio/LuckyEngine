#pragma once

namespace LuckyEngine
{
    /// <summary>
    /// Ӧ�ó��򣺹���Ӧ�ó������ڵ����������
    /// </summary>
    class Application
    {
    public:
        Application();
        virtual ~Application();

        /// <summary>
        /// ���У���ѭ��
        /// </summary>
        void Run();

        /// <summary>
        /// �ر�
        /// </summary>
        void Close();

        static Application& GetInstance() { return *s_Instance; }
    private:
        static Application* s_Instance;

        bool m_Running = true;  // ����״̬
    };

    /// <summary>
    /// ���� App���� LuckyApplication �ж���
    /// </summary>
    /// <returns></returns>
    Application* CreateApplication();
}