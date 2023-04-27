outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

VULKAN_SDK = os.getenv("VULKAN_SDK")

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"]  	  = "Vendor/glfw/include"
IncludeDir["ImGui"] 	  = "Vendor/imgui"
IncludeDir["stb_image"]   = "Vendor/stb_image"
IncludeDir["glm"]   	  = "Vendor/glm"
IncludeDir["VulkanSDK"]   = "%{VULKAN_SDK}/include"

LibraryDir = {}
LibraryDir["VulkanSDK"] 	= "%{VULKAN_SDK}/lib"

group "Dependencies"
	include "Vendor/glfw"
	include "Vendor/imgui"
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

	if not VULKAN_SDK then
		error("Vulkan not installed on this system")
	end

	files 
	{
		"%{prj.name}/src/**.h", 
		"%{prj.name}/src/**.cpp",
		"vendor/stb_image/stb_image.h"
	}

	includedirs 
	{
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.VulkanSDK}"
	}

	libdirs
	{
		"%{LibraryDir.VulkanSDK}"
	}

	defines
	{
		"GLFW_INCLUDE_NONE",
		"LOAD_VULKAN",
	}

	filter "system:windows"
		defines 
		{ 
			"_CRT_SECURE_NO_WARNINGS"
		}

		links
		{
			"GLFW",
			"ImGui",
			"vulkan-1.lib",
		}

		if not VULKAN_SDK then
			removelinks "vulkan-1.lib"
		end

		systemversion "latest"

	filter "system:linux"
		systemversion "latest"
	
	filter "configurations:Debug"
		defines "CF_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "CF_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "CF_DIST"
		runtime "Release"
		optimize "on"
		symbols "off"
group ""