#include "Application.h"
#include "PlatformSpecific/SDLOpenGL/SDLOpenGL.h"
#include "PlatformSpecific/GLFWVulkan/GLFWVulkan.h"
#include "PlatformSpecific/WIN32DX11/WIN32DX11.h"


Application* Application::Create(const ContextAPI& api, const Application::Specification& spec)
{
	switch (api)
	{
	case ContextAPI::None: fprintf(stderr, "Unknown API!"); return nullptr;
	case ContextAPI::SDLOpenGLES: return new SDLOpenGL(spec);
	case ContextAPI::GLFWVulkan: return new GLFWVulkan(spec);
	case ContextAPI::WIN32DX11: return new WIN32DX11(spec);
	}

	fprintf(stderr, "Unknown API!");
	return nullptr;
}

