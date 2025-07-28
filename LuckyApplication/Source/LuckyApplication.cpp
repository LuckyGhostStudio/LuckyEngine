#include <LuckyEngine.h>
#include <LuckyEngine/Core/EntryPoint.h>

/// <summary>
/// LuckyEngine Ӧ�ó�����
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