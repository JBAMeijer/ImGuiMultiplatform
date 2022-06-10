outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

VULKAN_SDK = os.getenv("VULKAN_SDK")
SDL2_SDK   = os.getenv("SDL2_SDK")

-- Include directories relative to root folder (solution directory)
IncludeDir = {}
IncludeDir["GLFW"]  	  = "vendor/glfw/include"
IncludeDir["ImGui"] 	  = "vendor/imgui"
IncludeDir["stb_image"]   = "vendor/stb_image"
IncludeDir["glm"]   	  = "vendor/glm"
IncludeDir["SDL2SDK"]     = "%{SDL2_SDK}/include"
IncludeDir["VulkanSDK"]   = "%{VULKAN_SDK}/include"

LibraryDir = {}
LibraryDir["SDL2SDKx64"] 	= "%{SDL2_SDK}/lib/x64"
LibraryDir["VulkanSDK"] 	= "%{VULKAN_SDK}/lib"

group "Dependencies"
	include "vendor/glfw"
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

	includedirs 
	{
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
		"%{IncludeDir.stb_image}",
		"%{IncludeDir.SDL2SDK}",
		"%{IncludeDir.VulkanSDK}"
	}

	libdirs
	{
		"%{LibraryDir.SDL2SDKx64}",
		"%{LibraryDir.VulkanSDK}"
	}

	if not VULKAN_SDK then
		removeincludedirs "%{IncludeDir.VulkanSDK}"
		removelibdirs "%{LibraryDir.VulkanSDK}"
		removefiles { "**/GLFWVulkan/**" }
		defines "REMOVE_VULKAN"
	end

	if not SDL2_SDK then
		removeincludedirs "%{IncludeDir.SDL2SDK}"
		removelibdirs "%{LibraryDir.SDL2SDKx64}"
		removefiles { "**/SDLOpenGL/**" }
		defines "REMOVE_SDL"
	end

	filter "system:windows"
		defines 
		{ 
			"_CRT_SECURE_NO_WARNINGS"
		}

		links
		{
			"GLFW",
			"ImGui",
			"SDL2.lib",
			"SDL2main.lib",
			"opengl32.lib",
			"vulkan-1.lib",
			"d3d12.lib",
			"d3dcompiler.lib",
			"dxgi.lib"
		}

		if not VULKAN_SDK then
			removelinks "vulkan-1.lib"
		end

		if not SDL2_SDK then
			removelinks { "SDL2.lib", "SDL2main.lib" }
		end

		systemversion "latest"

	filter "system:linux"
		removefiles { "**/WIN32DX12/**" }
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
group ""