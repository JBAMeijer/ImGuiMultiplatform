// Renderers
#include <backends/imgui_impl_opengl3.cpp>
#include <backends/imgui_impl_vulkan.cpp>
#if defined(SYSTEM_WINDOWS)
#include <backends/imgui_impl_dx12.cpp>
#endif

// Platforms
#include <backends/imgui_impl_sdl.cpp>
#include <backends/imgui_impl_glfw.cpp>
#if defined(SYSTEM_WINDOWS)
#include <backends/imgui_impl_win32.cpp>
#endif