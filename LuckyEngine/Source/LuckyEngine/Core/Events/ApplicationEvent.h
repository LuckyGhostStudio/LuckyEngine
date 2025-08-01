#pragma once

#include "Event.h"

namespace LuckyEngine
{
    /// <summary>
    /// 窗口改变大小事件
    /// </summary>
    class WindowResizeEvent : public Event
    {
    public:
        WindowResizeEvent(unsigned int width, unsigned int height) : m_Width(width), m_Height(height) {}

        std::string ToString() const override
        {
            std::stringstream ss;
            ss << "WindowResizeEvent: " << m_Width << ", " << m_Height;
            return ss.str();
        }

        inline unsigned int GetWidth() const { return m_Width; }
        inline unsigned int GetHeight() const { return m_Height; }

        /// <summary>
        /// 返回该事件的类型
        /// </summary>
        /// <returns>WindowResize 事件</returns>
        static EventType GetStaticType() { return EventType::WindowResize; }

        /// <summary>
        /// 返回该事件类型
        /// </summary>
        /// <returns>事件类型</returns>
        virtual EventType GetEventType() const override { return GetStaticType(); }

        /// <summary>
        /// 返回该事件名
        /// </summary>
        /// <returns>"WindowResize"</returns>
        virtual const char* GetName() const override { return "WindowResize"; }

        /// <summary>
        /// 返回事件种类标志
        /// </summary>
        /// <returns>EventCategoryApplication 事件</returns>
        virtual int GetCategoryFlags() const override { return EventCategoryApplication; }
    private:
        unsigned int m_Width;   // 被调整到的窗口宽
        unsigned int m_Height;  // 被调整到的窗口高
    };

    /// <summary>
    /// 窗口关闭事件
    /// </summary>
    class WindowCloseEvent : public Event
    {
    public:
        WindowCloseEvent() {}

        /// <summary>
        /// 返回该事件的类型
        /// </summary>
        /// <returns>WindowClose 事件</returns>
        static EventType GetStaticType() { return EventType::WindowClose; }

        /// <summary>
        /// 返回该事件类型
        /// </summary>
        /// <returns>事件类型</returns>
        virtual EventType GetEventType() const override { return GetStaticType(); }

        /// <summary>
        /// 返回该事件名
        /// </summary>
        /// <returns>"WindowClose"</returns>
        virtual const char* GetName() const override { return "WindowClose"; }

        /// <summary>
        /// 返回事件种类标志
        /// </summary>
        /// <returns>EventCategoryApplication 事件</returns>
        virtual int GetCategoryFlags() const override { return EventCategoryApplication; }
    };

    /// <summary>
    /// App 时钟事件
    /// </summary>
    class AppTickEvent : public Event
    {
    public:
        AppTickEvent() {}

        /// <summary>
        /// 返回该事件的类型
        /// </summary>
        /// <returns>AppTick 事件</returns>
        static EventType GetStaticType() { return EventType::AppTick; }

        /// <summary>
        /// 返回该事件类型
        /// </summary>
        /// <returns>事件类型</returns>
        virtual EventType GetEventType() const override { return GetStaticType(); }

        /// <summary>
        /// 返回该事件名
        /// </summary>
        /// <returns>"AppTick"</returns>
        virtual const char* GetName() const override { return "AppTick"; }

        /// <summary>
        /// 返回事件种类标志
        /// </summary>
        /// <returns>EventCategoryApplication 事件</returns>
        virtual int GetCategoryFlags() const override { return EventCategoryApplication; }
    };

    /// <summary>
    /// App 更新事件
    /// </summary>
    class AppUpdateEvent : public Event
    {
    public:
        AppUpdateEvent() {}

        /// <summary>
        /// 返回该事件的类型
        /// </summary>
        /// <returns>AppUpdate 事件</returns>
        static EventType GetStaticType() { return EventType::AppUpdate; }

        /// <summary>
        /// 返回该事件类型
        /// </summary>
        /// <returns>事件类型</returns>
        virtual EventType GetEventType() const override { return GetStaticType(); }

        /// <summary>
        /// 返回该事件名
        /// </summary>
        /// <returns>"AppUpdate"</returns>
        virtual const char* GetName() const override { return "AppUpdate"; }

        /// <summary>
        /// 返回事件种类标志
        /// </summary>
        /// <returns>EventCategoryApplication 事件</returns>
        virtual int GetCategoryFlags() const override { return EventCategoryApplication; }
    };

    /// <summary>
    /// App 渲染事件
    /// </summary>
    class AppRenderEvent : public Event
    {
    public:
        AppRenderEvent() {}

        /// <summary>
        /// 返回该事件的类型
        /// </summary>
        /// <returns>AppRender 事件</returns>
        static EventType GetStaticType() { return EventType::AppRender; }

        /// <summary>
        /// 返回该事件类型
        /// </summary>
        /// <returns>事件类型</returns>
        virtual EventType GetEventType() const override { return GetStaticType(); }

        /// <summary>
        /// 返回该事件名
        /// </summary>
        /// <returns>"AppRender"</returns>
        virtual const char* GetName() const override { return "AppRender"; }

        /// <summary>
        /// 返回事件种类标志
        /// </summary>
        /// <returns>EventCategoryApplication 事件</returns>
        virtual int GetCategoryFlags() const override { return EventCategoryApplication; }
    };
}