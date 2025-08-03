#pragma once

namespace LuckyEngine
{
    class Renderer2D
    {
    public:
        /// <summary>
        /// 初始化渲染器
        /// </summary>
        static void Init();

        static void Shutdown();

        /// <summary>
        /// 开始渲染场景
        /// </summary>
        static void BeginScene();

        /// <summary>
        /// 结束渲染场景
        /// </summary>
        static void EndScene();

        static void DrawRect(float x, float y, float width, float height, COLORREF color = RGB(255, 255, 255));
    };
}