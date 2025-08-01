#pragma once

#include "Logger.h"

namespace LuckyEngine
{
    /// <summary>
    /// ��־����
    /// </summary>
    class LogUtility
    {
    public:
        /// <summary>
        /// ��־������ڲ�ʵ��
        /// </summary>
        /// <param name="level">��־����</param>
        /// <param name="header">��־ͷ����Ϣ</param>
        /// <param name="message">��Ϣ</param>
        static void LogInternal(Logger::Level level, const std::string& header, const std::string& message);
    private:
        /// <summary>
        /// ���ÿ���̨��ɫ
        /// </summary>
        /// <param name="level">��־����</param>
        static void SetConsoleColor(Logger::Level level);

        /// <summary>
        /// ���ÿ���̨��ɫ
        /// </summary>
        static void ResetConsoleColor();
    };
}