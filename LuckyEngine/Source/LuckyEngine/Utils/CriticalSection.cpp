#include "lcpch.h"
#include "CriticalSection.h"

namespace LuckyEngine
{
    // ��̬��Ա��ʼ��
    CRITICAL_SECTION CriticalSection::s_CriticalSection;
    bool CriticalSection::s_Initialized = false;

    void CriticalSection::Init()
    {
        if (!s_Initialized)
        {
            // ��ʼ���ٽ���
            InitializeCriticalSection(&s_CriticalSection);
            s_Initialized = true;
        }
    }

    void CriticalSection::Shutdown()
    {
        if (s_Initialized)
        {
            // ɾ���ٽ���
            DeleteCriticalSection(&s_CriticalSection);
            s_Initialized = false;
        }
    }
}