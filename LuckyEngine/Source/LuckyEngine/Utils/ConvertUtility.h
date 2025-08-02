#pragma once

namespace LuckyEngine
{
    /// <summary>
    /// 类型转换工具类
    /// </summary>
    class ConvertUtility
    {
    public:
        /// <summary>
        /// 字符串转换为宽字符串
        /// </summary>
        /// <param name="str">输入字符串</param>
        /// <returns>转换后的宽字符串</returns>
        static std::wstring StringToWString(const std::string& str);

        /// <summary>
        /// 宽字符串转换为字符串
        /// </summary>
        /// <param name="wstr">输入宽字符串</param>
        /// <returns>转换后的字符串</returns>
        static std::string WStringToString(const std::wstring& wstr);
    };
}