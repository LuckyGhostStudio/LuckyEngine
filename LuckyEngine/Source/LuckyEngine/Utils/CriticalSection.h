#pragma once

namespace LuckyEngine
{
    /// <summary>
    /// �ٽ���
    /// </summary>
    class CriticalSection
    {
    public:
        static void Init();

        static void Shutdown();

        /// <summary>
        /// RAII�����󣬱�֤��ȫ��������
        /// </summary>
        class Lock
        {
        public:
            Lock()
            {
                // �����ٽ���
                EnterCriticalSection(&s_CriticalSection);
            }

            ~Lock()
            {
                // �뿪�ٽ���
                LeaveCriticalSection(&s_CriticalSection);
            }
        };
    private:
        static CRITICAL_SECTION s_CriticalSection;
        static bool s_Initialized;
    };
}