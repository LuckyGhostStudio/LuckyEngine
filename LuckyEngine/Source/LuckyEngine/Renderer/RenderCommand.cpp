#include "lcpch.h"
#include "RenderCommand.h"

namespace LuckyEngine
{
    void RenderCommand::Init()
    {
        
    }

    void RenderCommand::Shutdown()
    {
        
    }

    void RenderCommand::SetClearColor(COLORREF color)
    {
        setbkcolor(color);  // 设置背景颜色
    }

    void RenderCommand::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
    {
        Resize(nullptr, width, height); // 调整窗口大小
        Clear();
    }

    void RenderCommand::Clear()
    {
        cleardevice();
    }

    void RenderCommand::DrawRect(int x, int y, int width, int height, COLORREF color)
    {
        setcolor(color);
        setfillcolor(color);
        fillrectangle(x - width / 2, y - height / 2, x + width / 2, y + height / 2);
    }
}