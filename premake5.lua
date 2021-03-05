workspace "Prismarine"
	architecture "x64"

	configurations{
	
		"Debug",
		"Release",
		"Dist"

	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


-- Include directories relative to root folder
IncludeDir = {}
IncludeDir["GLFW"] = "Prismarine/vendor/GLFW/include"

include "Prismarine/vendor/GLFW"


project "Prismarine"
	location "Prismarine"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pmpch.h"
	pchsource "Prismarine/src/pmpch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links {
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
		
			"PM_PLATFORM_WINDOWS",
			"PM_BUILD_DLL"

		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ..\\bin\\" .. outputdir .. "\\Sandbox")
		}

	filter "configurations:Debug"
		defines "PM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PM_DIST"
		optimize "On"



project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Prismarine/vendor/spdlog/include",
		"Prismarine/src"
	}

	links{
		"Prismarine"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines{
		
			"PM_PLATFORM_WINDOWS"

		}

	filter "configurations:Debug"
		defines "PM_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "PM_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "PM_DIST"
		optimize "On"