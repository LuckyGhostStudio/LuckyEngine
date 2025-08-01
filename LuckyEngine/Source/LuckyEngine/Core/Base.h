#pragma once

#include <memory>

#ifdef LC_DEBUG
    #define LC_ENABLE_ASSERTS
#endif

#ifdef LC_ENABLE_ASSERTS    // ���ö���
    // ���ԣ�xΪ�� ����ʾERROR��־��Ϣ ���жϵ���
    #define LC_ASSERT(x, ...) { if(!(x)) { LC_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
    // ���ԣ�xΪ�� ����ʾERROR��־��Ϣ ���жϵ���
    #define LC_CORE_ASSERT(x, ...) { if(!(x)) { LC_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else   // ���ö���
    #define LC_ASSERT(x, ...)
    #define LC_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << x)     // 1 ���� x λ

// ���¼����� ���غ�������
#define LC_BIND_EVENT_FUNC(func) [this](auto&&... args) -> decltype(auto) { return this->func(std::forward<decltype(args)>(args)...); }

namespace LuckyEngine
{
    /// <summary>
    /// Ψһָ��
    /// </summary>
    /// <typeparam name="T">����</typeparam>
    template<typename T>
    using Scope = std::unique_ptr<T>;

    /// <summary>
    /// ����Ψһָ��
    /// </summary>
    /// <typeparam name="T">����</typeparam>
    /// <typeparam name="...Args">���������б�</typeparam>
    /// <param name="...args">�����б�</param>
    /// <returns></returns>
    template<typename T, typename ... Args>
    constexpr Scope<T> CreateScope(Args&& ... args)
    {
        return std::make_unique<T>(std::forward<Args>(args)...);
    }

    /// <summary>
    /// ����ָ��
    /// </summary>
    /// <typeparam name="T">����</typeparam>
    template<typename T>
    using Ref = std::shared_ptr<T>;

    /// <summary>
    /// ��������ָ��
    /// </summary>
    /// <typeparam name="T">����</typeparam>
    /// <typeparam name="...Args">���������б�</typeparam>
    /// <param name="...args">�����б�</param>
    /// <returns></returns>
    template<typename T, typename ... Args>
    constexpr Ref<T> CreateRef(Args&& ... args)
    {
        return std::make_shared<T>(std::forward<Args>(args)...);
    }
}