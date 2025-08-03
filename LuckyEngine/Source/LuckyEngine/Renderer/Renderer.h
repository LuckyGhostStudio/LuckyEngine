#pragma once

#include "RenderCommand.h"

namespace LuckyEngine
{
    /// <summary>
    /// ��Ⱦ��
    /// </summary>
    class Renderer
    {
    public:
        /// <summary>
        /// ��ʼ����Ⱦ��
        /// </summary>
        static void Init();

        /// <summary>
        /// �ر���Ⱦ��
        /// </summary>
        static void Shutdown();

        /// <summary>
        /// ��������ʱ����
        /// </summary>
        /// <param name="width">��</param>
        /// <param name="height">��</param>
        static void OnWindowResize(uint32_t width, uint32_t height);
    };
}