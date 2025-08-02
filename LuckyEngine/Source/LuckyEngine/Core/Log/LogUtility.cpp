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

        // ��ȡ��ǰʱ��
        std::time_t now = std::time(nullptr);
        localtime_s(&tm, &now);

        // ��ʽ��ʱ���ַ��� ʱ:��:��
        std::ostringstream timeStream;
        timeStream << std::setfill('0')
            << std::setw(2) << tm.tm_hour << ":"
            << std::setw(2) << tm.tm_min << ":"
            << std::setw(2) << tm.tm_sec;

        // ������ɫ
        LogUtility::SetConsoleColor(level);

        std::ostringstream logStream;
        logStream << header << ": " << message << std::endl;

        // �����־
        std::printf(logStream.str().c_str());

        // ������ɫ
        LogUtility::ResetConsoleColor();
    }

    void LogUtility::SetConsoleColor(Logger::Level level)
    {
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        WORD color = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;   // Ĭ�ϰ�ɫ

        switch (level)
        {
        case Logger::Level::Info:
            color = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;        // ��ɫ
            break;
        case Logger::Level::Warning:
            color = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;   // ��ɫ
            break;
        case Logger::Level::Error:
            color = FOREGROUND_RED | FOREGROUND_INTENSITY;  // ��ɫ
            break;
        }

        SetConsoleTextAttribute(console, color);
    }

    void LogUtility::ResetConsoleColor()
    {
        HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
        SetConsoleTextAttribute(console, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE); // ��ɫ
    }
}
