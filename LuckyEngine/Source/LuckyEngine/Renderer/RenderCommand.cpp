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
        setbkcolor(color);  // ���ñ�����ɫ
    }

    void RenderCommand::SetViewport(uint32_t x, uint32_t y, uint32_t width, uint32_t height)
    {
        Resize(nullptr, width, height); // �������ڴ�С
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