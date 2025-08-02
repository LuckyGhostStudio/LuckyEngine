#include "lcpch.h"
#include "ConvertUtility.h"

#include <codecvt>
namespace LuckyEngine
{
    std::wstring ConvertUtility::StringToWString(const std::string& str)
    {
        static std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> convert;
        return convert.from_bytes(str);
    }

    std::string ConvertUtility::WStringToString(const std::wstring& wstr)
    {
        static std::wstring_convert<std::codecvt_utf8<wchar_t>, wchar_t> convert;
        return convert.to_bytes(wstr);
    }
}