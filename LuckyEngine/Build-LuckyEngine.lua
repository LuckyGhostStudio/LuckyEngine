project "LuckyEngine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    targetdir "Binaries/%{cfg.buildcfg}"
    staticruntime "off"

    targetdir ("../Binaries/" .. outputdir .. "/%{prj.name}")
    objdir ("../Binaries/Intermediates/" .. outputdir .. "/%{prj.name}")

    pchheader "lcpch.h"     -- 预编译头文件
    pchsource "Source/lcpch.cpp"

    files
    {
        "Source/**.h",
        "Source/**.cpp",
    }

    includedirs         -- 附加包含目录
    {
        "Source",
        "Vendor",
        "Vendor/EasyX/include",
    }

    libdirs
    {
        "Vendor/EasyX/lib/x64",
    }

    links
    {
        "EasyXw.lib",
    }

    filter "system:windows"
        systemversion "latest"

    filter "configurations:Debug"
        defines { "LC_DEBUG" }
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines { "LC_RELEASE" }
        runtime "Release"
        optimize "On"
        symbols "On"

    filter "configurations:Dist"
        defines { "LC_DIST" }
        runtime "Release"
        optimize "On"
        symbols "Off"