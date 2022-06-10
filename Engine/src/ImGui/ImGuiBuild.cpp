#include <Base.h>
// Renderers

#include <backends/imgui_impl_opengl3.cpp>
#if defined(LOAD_VULKAN)
#include <backends/imgui_impl_vulkan.cpp>
#endif
#if defined(PLATFORM_WINDOWS)
#include <backends/imgui_impl_dx12.cpp>
#endif

// Platforms
#if defined(LOAD_SDL)
#include <backends/imgui_impl_sdl.cpp>
#endif
#include <backends/imgui_impl_glfw.cpp>
#if defined(PLATFORM_WINDOWS)
#include <backends/imgui_impl_win32.cpp>
#endif