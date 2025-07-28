-- premake5.lua
workspace "LuckyEngine"      -- 解决方案名称
    architecture "x64"  -- 体系结构
    configurations { "Debug", "Release", "Dist" }
    startproject "LuckyApplication"

    flags { "MultiProcessorCompile" }

outputdir = "%{cfg.system}-%{cfg.architecture}/%{cfg.buildcfg}"     -- 输出目录

group "Core"
    include "LuckyEngine/Build-LuckyEngine.lua"
group ""

include "LuckyApplication/Build-LuckyApplication.lua"