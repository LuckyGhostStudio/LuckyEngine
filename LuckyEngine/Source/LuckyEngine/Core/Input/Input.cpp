#include "lcpch.h"
#include "Input.h"

#include "LuckyEngine/Core/Application.h"

namespace LuckyEngine
{
    bool Input::IsKeyPressed(KeyCode keycode)
    {
        int vk = static_cast<int>(keycode);             // 获取按键状态

        return (GetAsyncKeyState(vk) & 0x8000) != 0;    // 高位表示按键是否按下
    }

    bool Input::IsMouseButtonPressed(MouseCode button)
    {
        int vk = static_cast<int>(button);  // 虚拟键码

        return (GetAsyncKeyState(vk) & 0x8000) != 0;    // 高位表示按键是否按下
    }

    std::pair<float, float> Input::GetMousePosition()
    {
        // 获取鼠标屏幕坐标
        POINT pt;
        GetCursorPos(&pt);

        // 转换为窗口客户区坐标
        ScreenToClient(GetHWnd(), &pt);

        return { static_cast<float>(pt.x), static_cast<float>(pt.y) };
    }

    float Input::GetMouseX()
    {
        return GetMousePosition().first;    // x 坐标
    }
    float Input::GetMouseY()
    {
        return GetMousePosition().second;   // y 坐标
    }
}