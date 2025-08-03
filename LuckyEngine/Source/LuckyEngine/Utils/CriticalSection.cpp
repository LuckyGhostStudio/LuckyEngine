#include "lcpch.h"
#include "CriticalSection.h"

namespace LuckyEngine
{
    // 静态成员初始化
    CRITICAL_SECTION CriticalSection::s_CriticalSection;
    bool CriticalSection::s_Initialized = false;

    void CriticalSection::Init()
    {
        if (!s_Initialized)
        {
            // 初始化临界区
            InitializeCriticalSection(&s_CriticalSection);
            s_Initialized = true;
        }
    }

    void CriticalSection::Shutdown()
    {
        if (s_Initialized)
        {
            // 删除临界区
            DeleteCriticalSection(&s_CriticalSection);
            s_Initialized = false;
        }
    }
}