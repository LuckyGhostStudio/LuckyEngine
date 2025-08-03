#include "lcpch.h"
#include "Renderer.h"

#include "Renderer2D.h"

namespace LuckyEngine
{
    void Renderer::Init()
    {
        RenderCommand::Init();
        Renderer2D::Init();
    }

    void Renderer::Shutdown()
    {
        Renderer2D::Shutdown();
        RenderCommand::Shutdown();
    }

    void Renderer::OnWindowResize(uint32_t width, uint32_t height)
    {
        RenderCommand::SetViewport(0, 0, width, height);    // �����ӿڴ�С
    }
}