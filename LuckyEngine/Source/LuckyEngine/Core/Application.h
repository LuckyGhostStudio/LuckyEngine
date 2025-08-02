#pragma once

#include "Events/ApplicationEvent.h"

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
        /// �¼��ص�����
        /// </summary>
        /// <param name="e">�¼�</param>
        void OnEvent(Event& event);

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
        /// <summary>
        /// ���ڹرջص�����
        /// </summary>
        /// <param name="e">���ڹر��¼�</param>
        /// <returns>�Ƿ��ѹر�</returns>
        bool OnWindowClose(WindowCloseEvent& e);

        /// <summary>
        /// ��������ʱ����
        /// </summary>
        /// <param name="e">���������¼�</param>
        /// <returns>�¼�������</returns>
        bool OnWindowResize(WindowResizeEvent& e);
    private:
        static Application* s_Instance;

        bool m_Running = true;      // ����״̬
        bool m_Minimized = false;   // ������С��
    };

    /// <summary>
    /// ���� App���� LuckyApplication �ж���
    /// </summary>
    /// <returns></returns>
    Application* CreateApplication();
}