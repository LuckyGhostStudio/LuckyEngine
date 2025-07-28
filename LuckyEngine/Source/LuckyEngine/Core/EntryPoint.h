#pragma once

extern LuckyEngine::Application* LuckyEngine::CreateApplication();

int main(int argc, char** argv)
{
    LuckyEngine::Application* app = LuckyEngine::CreateApplication(); // ´´½¨ Application

    app->Run();

    delete app;
}