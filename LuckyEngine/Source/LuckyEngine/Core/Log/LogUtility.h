#pragma once

#include "Logger.h"

namespace LuckyEngine
{
    /// <summary>
    /// 日志工具
    /// </summary>
    class LogUtility
    {
    public:
        /// <summary>
        /// 日志输出的内部实现
        /// </summary>
        /// <param name="level">日志级别</param>
        /// <param name="header">日志头部信息</param>
        /// <param name="message">信息</param>
        static void LogInternal(Logger::Level level, const std::string& header, const std::string& message);
    private:
        /// <summary>
        /// 设置控制台颜色
        /// </summary>
        /// <param name="level">日志级别</param>
        static void SetConsoleColor(Logger::Level level);

        /// <summary>
        /// 重置控制台颜色
        /// </summary>
        static void ResetConsoleColor();
    };
}