#include "lcpch.h"
#include "Renderer2D.h"

#include "RenderCommand.h"

namespace LuckyEngine
{
    void Renderer2D::Init()
    {

    }

    void Renderer2D::Shutdown()
    {

    }

    void Renderer2D::BeginScene()
    {
        
    }

    void Renderer2D::EndScene()
    {
    }

    void Renderer2D::DrawRect(float x, float y, float width, float height, COLORREF color)
    {
        RenderCommand::DrawRect((int)x, (int)y, (int)width, (int)height, color);
    }
}