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
        // �����󻺳�����֮�����Ⱦ�������ں󻺳�������
        BeginBatchDraw();
    }

    void EasyXContext::SwapBuffers()
    {
        FlushBatchDraw();   // ����ǰ�󻺳���
    }
}