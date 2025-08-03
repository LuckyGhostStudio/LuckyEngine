#pragma once

#include <graphics.h>

namespace LuckyEngine
{
    /// <summary>
    /// ��Ⱦ�����Ⱦ�ӿ������������Ⱦ����
    /// </summary>
    class RenderCommand
    {
    public:
        /// <summary>
        /// ��ʼ��
        /// </summary>
        static void Init();

        static void Shutdown();

        /// <summary>
        /// ����������ɫ
        /// </summary>
        /// <param name="color">������ɫ</param>
        static void SetClearColor(COLORREF color);

        /// <summary>
        /// �����ӿڴ�С
        /// </summary>
        /// <param name="x">���� x</param>
        /// <param name="y">���� y</param>
        /// <param name="width">��</param>
        /// <param name="height">��</param>
        static void SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height);

        /// <summary>
        /// ����
        /// </summary>
        static void Clear();

        static void DrawRect(int x, int y, int width, int height, COLORREF color = RGB(255, 255, 255));
    };
}