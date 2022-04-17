workspace "GUIAPP"
	architecture "x86_64"
	startproject "Client"

	configurations 
	{
		"Debug", 
		"Release", 
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"]  	  = "vendor/glfw/include"
IncludeDir["SDL2"]   	  = "vendor/SDL2/include"
IncludeDir["ImGui"] 	  = "vendor/imgui"
IncludeDir["stb_image"]   = "vendor/stb_image"
IncludeDir["glm"]   	  = "vendor/glm"

group "Dependencies"
	include "vendor/GLFW"
	include "vendor/imgui"
group ""

group "Core"
project "Engine"
	location "Engine"
	kind "StaticLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp",
		"vendor/stb_image/stb_image.h",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS",
	}

	includedirs 
	{
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.SDL2}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}"
	}

	libdirs
	{
		"vendor/SDL2/lib/x64",
	}

	links
	{
		"GLFW",
		"ImGui",
		"SDL2.lib",
		"SDL2main.lib",
		"opengl32.lib"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "TYPH_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "TYPH_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "TYPH_DIST"
		runtime "Release"
		optimize "on"
group ""

group "APP"
project "Client"
	location "Client"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files 
	{
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp"
	}

	includedirs 
	{
		"Engine/src",
		"vendor/SDL2/include",
		"vendor/imgui",
		"%{IncludeDir.glm}"
	}

	libdirs
	{
		"vendor/SDL2/lib/x64",
	}

	links 
	{
		"Engine"
	}

	filter "system:windows"
		systemversion "latest"

	filter "configurations:Debug"
		defines "TYPH_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "TYPH_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "TYPH_DIST"
		runtime "Release"
		optimize "on"
group ""