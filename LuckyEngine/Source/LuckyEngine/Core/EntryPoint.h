#pragma once

extern LuckyEngine::Application* LuckyEngine::CreateApplication();

int main(int argc, char** argv)
{
    LuckyEngine::Log::Init();

    LC_CORE_WARN("Initialized Log!");
    LC_INFO("Hello, Lucky Engine!");

    LuckyEngine::Application* app = LuckyEngine::CreateApplication(); // ´´½¨ Application

    app->Run();

    delete app;
}