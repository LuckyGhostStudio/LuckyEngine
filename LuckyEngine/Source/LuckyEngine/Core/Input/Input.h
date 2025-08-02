#pragma once

#include "LuckyEngine/Core/Base.h"
#include "LuckyEngine/Core/Input/KeyCodes.h"
#include "LuckyEngine/Core/Input/MouseButtonCodes.h"

namespace LuckyEngine
{
    class Input
    {
    public:
        /// <summary>
        /// �����Ƿ���
        /// </summary>
        /// <param name="keycode">��������</param>
        /// <returns>���</returns>
        static bool IsKeyPressed(KeyCode keycode);

        /// <summary>
        /// ��갴ť�Ƿ���
        /// </summary>
        /// <param name="button">��ť����</param>
        /// <returns>���</returns>
        static bool IsMouseButtonPressed(MouseCode button);

        /// <summary>
        /// �������λ������
        /// </summary>
        /// <returns>���λ��(x, y)</returns>
        static std::pair<float, float> GetMousePosition();

        /// <summary>
        /// �������x����
        /// </summary>
        /// <returns>��� x ����</returns>
        static float GetMouseX();

        /// <summary>
        /// �������y����
        /// </summary>
        /// <returns>��� y ����</returns>
        static float GetMouseY();
    };
}