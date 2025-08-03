#include "lcpch.h"
#include "ConvertUtility.h"

namespace LuckyEngine
{
    std::wstring ConvertUtility::StringToWString(const std::string& str)
    {
        int size = MultiByteToWideChar(CP_UTF8, 0, str.data(), (int)str.size(), nullptr, 0);
        std::wstring result(size, 0);
        MultiByteToWideChar(CP_UTF8, 0, str.data(), (int)str.size(), result.data(), size);

        return result;
    }

    std::string ConvertUtility::WStringToString(const std::wstring& wstr)
    {
        int size = WideCharToMultiByte(CP_UTF8, 0, wstr.data(), (int)wstr.size(), nullptr, 0, nullptr, nullptr);
        std::string result(size, 0);
        WideCharToMultiByte(CP_UTF8, 0, wstr.data(), (int)wstr.size(), result.data(), size, nullptr, nullptr);

        return result;
    }
}