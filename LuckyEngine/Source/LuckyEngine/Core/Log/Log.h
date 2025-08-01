#pragma once

#include "LuckyEngine/Core/Base.h"
#include "LogUtility.h"

namespace LuckyEngine
{
    /// <summary>
    /// 日志：用于输出和记录日志信息
    /// </summary>
    class Log
    {
    public:
        /// <summary>
        /// 初始化
        /// </summary>
        static void Init();
    public:
        static Ref<Logger>& GetCoreLogger() { return s_CoreLogger; }
        static Ref<Logger>& GetClientLogger() { return s_ClientLogger; }
    private:
        static Ref<Logger> s_CoreLogger;    // 内核日志
        static Ref<Logger> s_ClientLogger;  // 客户端日志
    };
}

// 内核日志
#define LC_CORE_INFO(...)   ::LuckyEngine::Log::GetCoreLogger()->Info(__VA_ARGS__)
#define LC_CORE_WARN(...)   ::LuckyEngine::Log::GetCoreLogger()->Warning(__VA_ARGS__)
#define LC_CORE_ERROR(...)  ::LuckyEngine::Log::GetCoreLogger()->Error(__VA_ARGS__)

// 客户端日志
#define LC_INFO(...)        ::LuckyEngine::Log::GetClientLogger()->Info(__VA_ARGS__)
#define LC_WARN(...)        ::LuckyEngine::Log::GetClientLogger()->Warning(__VA_ARGS__)
#define LC_ERROR(...)       ::LuckyEngine::Log::GetClientLogger()->Error(__VA_ARGS__)