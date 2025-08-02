#include "lcpch.h"
#include "LogUtility.h"

#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>

namespace LuckyEngine
{
    void LogUtility::LogInternal(Logger::Level level, const std::string& header, const std::string& message)
    {
        std::tm tm = {};

        // 获取当前时间
        std::time_t now = std::time(nullptr);
        localtime_s(&tm, &now);

        // 格式化时间字符串 时:分:秒
        std::ostringstream timeStream;
        timeStream << std::setfill('0')
            << std::setw(2) << tm.tm_hour << ":"
            << std::setw(2) << tm.tm_min << ":"
            << std::setw(2) << tm.tm_sec;

        // 设置颜色
        LogUtility::SetConsoleColor(level);

        std::ostringstream logStream;
        logStream << header << ": " << message << std::endl;

        // 输出日志
        std::printf(logStream.str().c_str());

        // 重置颜色
        LogUtility::ResetConsoleColor();
    }

    void LogUtility::SetConsoleColor(Logger::Level level)
    {
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        WORD color = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;   // 默认白色

        switch (level)
        {
        case Logger::Level::Info:
            color = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;        // 白色
            break;
        case Logger::Level::Warning:
            color = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;   // 黄色
            break;
        case Logger::Level::Error:
            color = FOREGROUND_RED | FOREGROUND_INTENSITY;  // 红色
            break;
        }

        SetConsoleTextAttribute(console, color);
    }

    void LogUtility::ResetConsoleColor()
    {
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // 白色
    }
}
