#pragma once

namespace LuckyEngine
{
    /// <summary>
    /// 临界区
    /// </summary>
    class CriticalSection
    {
    public:
        static void Init();

        static void Shutdown();

        /// <summary>
        /// RAII锁对象，保证安全加锁解锁
        /// </summary>
        class Lock
        {
        public:
            Lock()
            {
                // 进入临界区
                EnterCriticalSection(&s_CriticalSection);
            }

            ~Lock()
            {
                // 离开临界区
                LeaveCriticalSection(&s_CriticalSection);
            }
        };
    private:
        static CRITICAL_SECTION s_CriticalSection;
        static bool s_Initialized;
    };
}