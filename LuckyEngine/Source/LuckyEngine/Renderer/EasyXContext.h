#pragma once

#include <graphics.h>

namespace LuckyEngine
{
    /// <summary>
    /// OpenGL ������
    /// </summary>
    class EasyXContext
    {
    public:
        /// <summary>
        /// ���� OpenGL ������
        /// </summary>
        /// <param name="windowHandle">���ھ��</param>
        /// <returns></returns>
        static Scope<EasyXContext> Create(HWND windowHandle);

        EasyXContext(HWND windowHandle);

        /// <summary>
        /// ��ʼ��
        /// </summary>
        void Init();

        /// <summary>
        /// ����ǰ�󻺳�
        /// </summary>
        void SwapBuffers();
    private:
        HWND m_WindowHandle;    // EasyX ���ھ��
    };
}