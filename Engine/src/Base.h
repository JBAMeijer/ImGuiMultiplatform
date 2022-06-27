#pragma once

#define REMOVE_VULKAN2 REMOVE_VULKAN
#define REMOVE_SDL2 REMOVE_SDL

#if defined(_WIN32)
	#if defined(_WIN64)
		#define PLATFORM_WINDOWS
	#else
		#error "32-bit builds are not supported!"
	#endif
#elif defined(__linux__)
	#define PLATFORM_LINUX
#else
	#error "Unknown or unsupported platform!"
#endif

#if REMOVE_VULKAN2 == 0
#define LOAD_VULKAN
#endif

#if REMOVE_SDL2 == 0
#define LOAD_SDL
#endif