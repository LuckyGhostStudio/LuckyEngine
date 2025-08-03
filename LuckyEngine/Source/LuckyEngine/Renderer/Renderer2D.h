#pragma once

namespace LuckyEngine
{
    class Renderer2D
    {
    public:
        /// <summary>
        /// ��ʼ����Ⱦ��
        /// </summary>
        static void Init();

        static void Shutdown();

        /// <summary>
        /// ��ʼ��Ⱦ����
        /// </summary>
        static void BeginScene();

        /// <summary>
        /// ������Ⱦ����
        /// </summary>
        static void EndScene();

        static void DrawRect(float x, float y, float width, float height, COLORREF color = RGB(255, 255, 255));
    };
}