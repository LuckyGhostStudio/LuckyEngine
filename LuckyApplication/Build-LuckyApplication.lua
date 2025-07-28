project "LuckyApplication"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    targetdir "Binaries/%{cfg.buildcfg}"
    staticruntime "off"

    targetdir ("../Binaries/" .. outputdir .. "/%{prj.name}")
    objdir ("../Binaries/Intermediates/" .. outputdir .. "/%{prj.name}")

    files 
    { 
        "Source/**.h",
        "Source/**.cpp",
    }

    includedirs
    {
        "Source",
        "%{wks.location}/LuckyEngine/Source",
        "%{wks.location}/LuckyEngine/Vendor",
        "%{wks.location}/LuckyEngine/Vendor/EasyX/include",
    }

    libdirs
    {
        "%{wks.location}/LuckyEngine/Vendor/EasyX/lib/x64",
    }

    links
    {
        "LuckyEngine",
        "EasyXw.lib",
    }

    filter "system:windows"
        systemversion "latest"
        defines { "WINDOWS" }

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