#pragma once

#include "lcpch.h"

namespace LuckyEngine
{
    /// <summary>
    /// �¼�����
    /// </summary>
    enum class EventType
    {
        None = 0,

        WindowClose,            // ���ڹر��¼�
        WindowResize,           // ���ڴ�С�ı��¼�
        WindowFocus,            // ���ھ۽��¼�
        WindowLostFocus,        // ����ʧ���¼�
        WindowMoved,            // �����ƶ��¼�

        AppTick,                // Appʱ���¼�
        AppUpdate,              // Appÿ֡�����¼�
        AppRender,              // App��Ⱦ�¼�

        KeyPressed,             // ���������¼�
        KeyReleased,            // ����̧���¼�
        keyTyped,               // ���������ַ��¼�

        MouseButtonPressed,     // ��갴ť�����¼�
        MouseButtonReleased,    // ��갴ţ̌���¼�
        MouseMoved,             // ����ƶ��¼�
        MouseScrolled           // �����ֹ����¼�
    };

    /// <summary>
    /// �¼�����
    /// </summary>
    enum EventCategory
    {
        None = 0,
        EventCategoryApplication    = BIT(0),   // 1  App ���¼�
        EventCategoryInput          = BIT(1),   // 2  �������¼�
        EventCategoryKeyboard       = BIT(2),   // 4  �������¼�
        EventCategoryMouse          = BIT(3),   // 8  ������¼�
        EventCategoryMouseButton    = BIT(4)    // 16 ��갴ť���¼�
    };

    /// <summary>
    /// �¼���
    /// </summary>
    class Event
    {
        friend class EventDispatcher;   // �¼�������
    public:
        /// <summary>
        /// �����¼�����
        /// </summary>
        /// <returns>�¼�����</returns>
        virtual EventType GetEventType() const = 0;

        /// <summary>
        /// �����¼���
        /// </summary>
        /// <returns>�¼���</returns>
        virtual const char* GetName() const = 0;

        /// <summary>
        /// �����¼�����־
        /// </summary>
        /// <returns>�¼�����־</returns>
        virtual int GetCategoryFlags() const = 0;

        /// <summary>
        /// �����¼������ַ���
        /// </summary>
        /// <returns>�¼���</returns>
        virtual std::string ToString() const { return GetName(); }

        /// <summary>
        /// ��ǰ�¼��Ƿ���Ŀ���¼�������
        /// </summary>
        /// <param name="category">Ŀ���¼�����</param>
        /// <returns>���</returns>
        inline bool IsInCategory(EventCategory category)
        {
            return GetCategoryFlags() & category;    // �¼�����־�� Ŀ���¼���� ��λ��
        }
    public:
        bool m_Handled = false; // �Ƿ��Ѵ���
    };

    /// <summary>
    /// �¼�������
    /// </summary>
    class EventDispatcher
    {
        template<typename T>
        using EventFn = std::function<bool(T&)>;    // �¼����� bool func(T&)
    public:
        EventDispatcher(Event& event) : m_Event(event) {}

        /// <summary>
        /// �¼�����
        /// </summary>
        /// <typeparam name="T">����</typeparam>
        /// <param name="func">�¼�����</param>
        /// <returns>���Ƚ��</returns>
        template<typename T>
        bool Dispatch(EventFn<T> func)
        {
            // ���յ����¼����� == �¼���������
            if (m_Event.GetEventType() == T::GetStaticType())
            {
                m_Event.m_Handled = func(*(T*)&m_Event);    // ִ���¼�����
                return true;
            }
            return false;
        }
    private:
        Event& m_Event;     // ��ǰ���յ��¼�
    };

    /// <summary>
    /// �������������������¼�
    /// </summary>
    /// <param name="os">���������</param>
    /// <param name="e">�¼�</param>
    /// <returns>����¼�</returns>
    inline std::ostream& operator<<(std::ostream& os, const Event& e)
    {
        return os << e.ToString();
    }
}