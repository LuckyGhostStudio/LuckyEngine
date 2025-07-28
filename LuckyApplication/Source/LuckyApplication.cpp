#include <LuckyEngine.h>
#include <LuckyEngine/Core/EntryPoint.h>

/// <summary>
/// LuckyEngine 应用程序类
/// </summary>
class LuckyApplication : public LuckyEngine::Application
{
public:
    LuckyApplication()
        : LuckyEngine::Application()
    {

    }
};

LuckyEngine::Application* LuckyEngine::CreateApplication()
{
    return new LuckyApplication();
}