#pragma once

namespace LuckyEngine
{
    enum class MouseCode : uint32_t
    {
        Button0 = VK_LBUTTON,      // ������
        Button1 = VK_RBUTTON,      // ����Ҽ�
        Button2 = VK_MBUTTON,      // ����м�

        ButtonLeft = Button0,
        ButtonRight = Button1,
        ButtonMiddle = Button2
    };
}