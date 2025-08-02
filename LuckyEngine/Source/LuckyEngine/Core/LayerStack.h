#pragma once

#include <vector>

#include "LuckyEngine/Core/Base.h"
#include "Layer.h"

namespace LuckyEngine
{
    /*
     * ��ͨ�����б�ǰ�벿�� ���ǲ����б��벿��
     * ���ǲ㣺GUI��Guizmo ��
     */

    /// <summary>
    /// ��ջ
    /// </summary>
    class LayerStack
    {
    public:
        LayerStack();
        ~LayerStack();

        /// <summary>
        /// �����ͨ��
        /// </summary>
        /// <param name="layer">��</param>
        void PushLayer(Layer* layer);

        /// <summary>
        /// ��Ӹ��ǲ㵽ջ��
        /// </summary>
        /// <param name="overlay">���ǲ�</param>
        void PushOverlay(Layer* overlay);

        /// <summary>
        /// �Ƴ���ͨ��
        /// </summary>
        /// <param name="layer">��ͨ��</param>
        void PopLayer(Layer* layer);

        /// <summary>
        /// �Ƴ����ǲ�
        /// </summary>
        /// <param name="overlay">���ǲ�</param>
        void PopOverlay(Layer* overlay);

        std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
        std::vector<Layer*>::iterator end() { return m_Layers.end(); }
    private:
        std::vector<Layer*> m_Layers;           // ���б�
        unsigned int m_LayerInsertIndex = 0;    // ����λ������
    };
}