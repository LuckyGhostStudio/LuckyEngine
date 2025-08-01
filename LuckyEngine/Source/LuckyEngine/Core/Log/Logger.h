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
        /// 日志级别
        /// </summary>
        enum class Level
        {
            Info,       // 信息
            Warning,    // 警告
            Error       // 错误
        };

        Logger(const std::string& header) : m_Header(header) {}

        /// <summary>
        /// 日志输出
        /// </summary>
        /// <typeparam name="...Args">信息参数类型列表</typeparam>
        /// <param name="level">日志级别</param>
        /// <param name="...args">信息参数列表</param>
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
        std::string m_Header;   // 日志头部信息
    };
}