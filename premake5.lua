workspace "Prismarine"
	architecture "x64"
	startproject "Sandbox"

	configurations{
	
		"Debug",
		"Release",
		"Dist"

	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"


-- Include directories relative to root folder
IncludeDir = {}
IncludeDir["GLFW"] = "Prismarine/vendor/GLFW/include"
IncludeDir["Glad"] = "Prismarine/vendor/Glad/include"
IncludeDir["ImGui"] = "Prismarine/vendor/imgui"
IncludeDir["glm"] = "Prismarine/vendor/glm"

include "Prismarine/vendor/GLFW"
include "Prismarine/vendor/Glad"
include "Prismarine/vendor/imgui"


project "Prismarine"
	location "Prismarine"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "pmpch.h"
	pchsource "Prismarine/src/pmpch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/vendor/glm/glm/**.hpp",
		"%{prj.name}/vendor/glm/glm/**.inl"
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}"
	}

	links {
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines{
		
			"PM_PLATFORM_WINDOWS",
			"PM_BUILD_DLL",
			"GLFW_INCLUDE_NONE"

		}

		postbuildcommands{
			("{COPY} %{cfg.buildtarget.relpath} ..\\bin\\" .. outputdir .. "\\Sandbox")
		}

	filter "configurations:Debug"
		defines "PM_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "PM_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "PM_DIST"
		runtime "Release"
		optimize "On"



project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Prismarine/vendor/spdlog/include",
		"Prismarine/src",
		"%{IncludeDir.glm}"
	}

	links{
		"Prismarine"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"

		defines{
		
			"PM_PLATFORM_WINDOWS"

		}

	filter "configurations:Debug"
		defines "PM_DEBUG"
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines "PM_RELEASE"
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines "PM_DIST"
		runtime "Release"
		optimize "On"