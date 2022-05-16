#pragma once

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