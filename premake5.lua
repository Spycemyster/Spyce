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
IncludeDir["Glad"] = "Spyce/vendor/Glad/include"
IncludeDir["imgui"] = "Spyce/vendor/imgui"

include "Spyce/vendor/GLFW"
include "Spyce/vendor/Glad"
include "Spyce/vendor/imgui"

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
        "%{IncludeDir.GLFW}",
        "%{IncludeDir.Glad}",
        "%{IncludeDir.imgui}"
    }

    links
    {
        "GLFW",
        "Glad",
        "imgui",
        "opengl32.lib"
    }


    filter "system:windows"
        cppdialect "C++20"
        staticruntime "on"
        systemversion "latest"

        defines
        {
            "SC_PLATFORM_WINDOWS",
            "SC_BUILD_DLL",
            "GLFW_INCLUDE_NONE"
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
        buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "SC_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "SC_DIST"
        buildoptions "/MD"
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
        buildoptions "/MDd"
        symbols "On"

    filter "configurations:Release"
        defines "SC_RELEASE"
        buildoptions "/MD"
        optimize "On"

    filter "configurations:Dist"
        defines "SC_DIST"
        buildoptions "/MD"
        optimize "On"