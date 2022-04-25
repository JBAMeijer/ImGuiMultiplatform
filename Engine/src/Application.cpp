#include "Application.h"
#include "PlatformSpecific/None/None.h"
#include "PlatformSpecific/SDLOpenGL/SDLOpenGL.h"
#include "PlatformSpecific/GLFWVulkan/GLFWVulkan.h"
#if defined(SYSTEM_WINDOWS)
#include "PlatformSpecific/WIN32DX12/WIN32DX12.h"
#endif

Application* Application::Create(const ContextAPI& api, const Application::Specification& spec)
{
	switch (api)
	{
	case ContextAPI::None: return new None(spec);
	case ContextAPI::SDLOpenGL: return new SDLOpenGL(spec);
	case ContextAPI::GLFWVulkan: return new GLFWVulkan(spec);
#if defined(SYSTEM_WINDOWS)
	case ContextAPI::WIN32DX12: return new WIN32DX12(spec);
#endif
	}

	fprintf(stderr, "Unknown API!");
	return nullptr;
}

