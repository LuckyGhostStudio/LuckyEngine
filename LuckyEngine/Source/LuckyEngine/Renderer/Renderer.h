#pragma once

#include "RenderCommand.h"

namespace LuckyEngine
{
    /// <summary>
    /// 渲染器
    /// </summary>
    class Renderer
    {
    public:
        /// <summary>
        /// 初始化渲染器
        /// </summary>
        static void Init();

        /// <summary>
        /// 关闭渲染器
        /// </summary>
        static void Shutdown();

        /// <summary>
        /// 窗口缩放时调用
        /// </summary>
        /// <param name="width">宽</param>
        /// <param name="height">高</param>
        static void OnWindowResize(uint32_t width, uint32_t height);
    };
}