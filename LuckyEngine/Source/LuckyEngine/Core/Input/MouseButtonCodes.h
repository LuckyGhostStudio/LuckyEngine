#pragma once

namespace LuckyEngine
{
    enum class MouseCode : uint32_t
    {
        Button0 = VK_LBUTTON,      // ЪѓБъзѓМќ
        Button1 = VK_RBUTTON,      // ЪѓБъгвМќ
        Button2 = VK_MBUTTON,      // ЪѓБъжаМќ

        ButtonLeft = Button0,
        ButtonRight = Button1,
        ButtonMiddle = Button2
    };
}