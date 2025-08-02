#pragma once

#include "LuckyEngine/Core/Base.h"
#include "LuckyEngine/Core/Events/Event.h"

namespace LuckyEngine
{
    class Layer
    {
    public:
        Layer(const std::string& name = "Layer");

        virtual ~Layer();

        /// <summary>
        /// ��ӵ���ջʱ����
        /// </summary>
        virtual void OnAttach() {}

        /// <summary>
        /// �Ӳ�ջ�Ƴ�ʱ����
        /// </summary>
        virtual void OnDetach() {}

        /// <summary>
        /// �����ʱ���ã�ÿ֡����
        /// </summary>
        virtual void OnUpdate() {}

        /// <summary>
        /// ��ȾImGui
        /// </summary>
        virtual void OnImGuiRender() {}

        /// <summary>
        /// �¼��ص�����
        /// </summary>
        /// <param name="event">�¼�</param>
        virtual void OnEvent(Event& event) {}

        inline const std::string& GetName() const { return m_DebugName; }
    protected:
        std::string m_DebugName;    // Layer �� Debug ģʽ�е�����
    };
}