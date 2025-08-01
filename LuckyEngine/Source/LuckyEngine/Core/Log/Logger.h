#pragma once

#include <string>
#include <sstream>

namespace LuckyEngine
{
    class LogUtility;

    class Logger
    {
    public:
        /// <summary>
        /// ��־����
        /// </summary>
        enum class Level
        {
            Info,       // ��Ϣ
            Warning,    // ����
            Error       // ����
        };

        Logger(const std::string& header) : m_Header(header) {}

        /// <summary>
        /// ��־���
        /// </summary>
        /// <typeparam name="...Args">��Ϣ���������б�</typeparam>
        /// <param name="level">��־����</param>
        /// <param name="...args">��Ϣ�����б�</param>
        template<typename... Args>
        void Log(Level level, Args&&... args)
        {
            std::ostringstream stream;
            ((stream << std::forward<Args>(args)), ...);
            LogUtility::LogInternal(level, m_Header, stream.str());
        }

        template<typename... Args>
        void Info(Args&&... args)
        {
            Log(Level::Info, std::forward<Args>(args)...);
        }

        template<typename... Args>
        void Warning(Args&&... args)
        {
            Log(Level::Warning, std::forward<Args>(args)...);
        }

        template<typename... Args>
        void Error(Args&&... args)
        {
            Log(Level::Error, std::forward<Args>(args)...);
        }
    private:
        std::string m_Header;   // ��־ͷ����Ϣ
    };
}