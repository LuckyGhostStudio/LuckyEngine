#pragma once

#include <graphics.h>

namespace LuckyEngine
{
    /// <summary>
    /// OpenGL 上下文
    /// </summary>
    class EasyXContext
    {
    public:
        /// <summary>
        /// 创建 OpenGL 上下文
        /// </summary>
        /// <param name="windowHandle">窗口句柄</param>
        /// <returns></returns>
        static Scope<EasyXContext> Create(HWND windowHandle);

        EasyXContext(HWND windowHandle);

        /// <summary>
        /// 初始化
        /// </summary>
        void Init();

        /// <summary>
        /// 交换前后缓冲
        /// </summary>
        void SwapBuffers();
    private:
        HWND m_WindowHandle;    // EasyX 窗口句柄
    };
}