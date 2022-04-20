workspace "Spyce"
    architecture "x64"

    configurations
    {
        -- Contains all debug functionality as well --
        "Debug",
        -- Stripped of most debug functionality but includes log messaging --
        "Release",
        -- Stripped of all debug functionality --
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Spyce/vendor/GLFW/include"

include "Spyce/vendor/GLFW"

project "Spyce"
    location "Spyce"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    pchheader "scpch.h"
    pchsource "Spyce/src/scpch.cpp"

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "%{prj.name}/vendor/spdlog/include",
        "%{prj.name}/src",
        "%{IncludeDir.GLFW}"
    }

    links
    {
        "GLFW",
        "opengl32.lib"
    }


    filter "system:windows"
        cppdialect "C++20"
        staticruntime "off"
        systemversion "latest"

        defines
        {
            "SC_PLATFORM_WINDOWS",
            "SC_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines 
        {
            "SC_DEBUG",
            "SC_ENABLE_ASSERTS"
        }
        symbols "On"

    filter "configurations:Release"
        defines "SC_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "SC_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp"
    }

    includedirs
    {
        "Spyce/vendor/spdlog/include",
        "Spyce/src"
    }

    links
    {
        "Spyce"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "SC_PLATFORM_WINDOWS",
        }

    filter "configurations:Debug"
        defines 
        {
            "SC_DEBUG",
            "SC_ENABLE_ASSERTS"
        }
        symbols "On"

    filter "configurations:Release"
        defines "SC_RELEASE"
        optimize "On"

    filter "configurations:Dist"
        defines "SC_DIST"
        optimize "On"