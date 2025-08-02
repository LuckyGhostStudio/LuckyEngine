#pragma once

namespace LuckyEngine
{
    /// <summary>
    /// ����ת��������
    /// </summary>
    class ConvertUtility
    {
    public:
        /// <summary>
        /// �ַ���ת��Ϊ���ַ���
        /// </summary>
        /// <param name="str">�����ַ���</param>
        /// <returns>ת����Ŀ��ַ���</returns>
        static std::wstring StringToWString(const std::string& str);

        /// <summary>
        /// ���ַ���ת��Ϊ�ַ���
        /// </summary>
        /// <param name="wstr">������ַ���</param>
        /// <returns>ת������ַ���</returns>
        static std::string WStringToString(const std::wstring& wstr);
    };
}