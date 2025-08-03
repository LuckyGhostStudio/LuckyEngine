#include "lcpch.h"
#include "EasyXContext.h"

namespace LuckyEngine
{
    Scope<EasyXContext> EasyXContext::Create(HWND windowHandle)
    {
        return CreateScope<EasyXContext>(windowHandle);
    }

    EasyXContext::EasyXContext(HWND windowHandle)
        : m_WindowHandle(windowHandle)
    {
        LC_CORE_ASSERT(m_WindowHandle, "Window handle is null!");
    }

    void EasyXContext::Init()
    {
        // 创建后缓冲区：之后的渲染操作都在后缓冲区进行
        BeginBatchDraw();
    }

    void EasyXContext::SwapBuffers()
    {
        FlushBatchDraw();   // 交换前后缓冲区
    }
}