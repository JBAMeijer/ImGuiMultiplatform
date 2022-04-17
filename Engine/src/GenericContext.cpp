#include "GenericContext.h"
#include "PlatformSpecific/SDL_OpenGLES/SDLOpenGLES.h"
#include "Application.h"

GenericContext* GenericContext::Create(const ContextAPI& api, const ApplicationSpecification& Specification)
{
	switch (api)
	{
	case ContextAPI::SDLOpenGLES: return new SDL_OpenGL(Specification);
	case ContextAPI::GLFWVulkan: return nullptr;
	default:
		break;
	}
}
