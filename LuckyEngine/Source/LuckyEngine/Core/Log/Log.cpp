#include "lcpch.h"
#include "Log.h"

namespace LuckyEngine
{
    Ref<Logger> Log::s_CoreLogger;
    Ref<Logger> Log::s_ClientLogger;

    void Log::Init()
    {
        s_CoreLogger = CreateRef<Logger>("Lucky");
        s_ClientLogger = CreateRef<Logger>("APP");
    }
}