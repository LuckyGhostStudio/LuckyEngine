#include "lcpch.h"
#include "Input.h"

#include "LuckyEngine/Core/Application.h"

namespace LuckyEngine
{
    bool Input::IsKeyPressed(KeyCode keycode)
    {
        int vk = static_cast<int>(keycode);             // ��ȡ����״̬

        return (GetAsyncKeyState(vk) & 0x8000) != 0;    // ��λ��ʾ�����Ƿ���
    }

    bool Input::IsMouseButtonPressed(MouseCode button)
    {
        int vk = static_cast<int>(button);  // �������

        return (GetAsyncKeyState(vk) & 0x8000) != 0;    // ��λ��ʾ�����Ƿ���
    }

    std::pair<float, float> Input::GetMousePosition()
    {
        // ��ȡ�����Ļ����
        POINT pt;
        GetCursorPos(&pt);

        // ת��Ϊ���ڿͻ�������
        ScreenToClient(GetHWnd(), &pt);

        return { static_cast<float>(pt.x), static_cast<float>(pt.y) };
    }

    float Input::GetMouseX()
    {
        return GetMousePosition().first;    // x ����
    }
    float Input::GetMouseY()
    {
        return GetMousePosition().second;   // y ����
    }
}