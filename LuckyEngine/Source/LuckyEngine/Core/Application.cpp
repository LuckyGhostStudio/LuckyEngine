#include "lcpch.h"
#include "Application.h"

namespace LuckyEngine
{
    Application* Application::s_Instance = nullptr;

    Application::Application()
    {
        if (!s_Instance)
        {
            s_Instance = this;
        }
    }

    Application::~Application()
    {

    }

    void Application::Run()
    {
        while (m_Running)
        {
            std::cout << "Update" << std::endl;
        }
    }

    void Application::Close()
    {
        m_Running = false;
    }
}