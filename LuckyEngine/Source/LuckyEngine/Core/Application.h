#pragma once

#include "Window.h"
#include "Events/ApplicationEvent.h"
#include "LayerStack.h"

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
        /// �����ͨ�㵽��ջ
        /// </summary>
        /// <param name="layer">��ͨ��</param>
        void PushLayer(Layer* layer) { m_LayerStack.PushLayer(layer); }

        /// <summary>
        /// ��Ӹ��ǲ㵽��ջ
        /// </summary>
        /// <param name="layer">���ǲ�</param>
        void PushOverlay(Layer* layer) { m_LayerStack.PushOverlay(layer); }

        /// <summary>
        /// �Ӳ�ջ�Ƴ���ͨ��
        /// </summary>
        /// <param name="layer">��ͨ��</param>
        void PopLayer(Layer* layer) { m_LayerStack.PopLayer(layer); }

        /// <summary>
        /// �Ӳ�ջ�Ƴ����ǲ�
        /// </summary>
        /// <param name="layer">���ǲ�</param>
        void PopOverlay(Layer* layer) { m_LayerStack.PopOverlay(layer); }

        /// <summary>
        /// �¼��ص�����
        /// </summary>
        /// <param name="e">�¼�</param>
        void OnEvent(Event& e);

        /// <summary>
        /// ���У���ѭ��
        /// </summary>
        void Run();

        /// <summary>
        /// �ر�
        /// </summary>
        void Close();

        Window& GetWindow() { return *m_Window; }
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

        Scope<Window> m_Window;     // ����
        LayerStack m_LayerStack;    // ��ջ

        bool m_Running = true;      // ����״̬
        bool m_Minimized = false;   // ������С��
    };

    /// <summary>
    /// ���� App���� LuckyApplication �ж���
    /// </summary>
    /// <returns></returns>
    Application* CreateApplication();
}