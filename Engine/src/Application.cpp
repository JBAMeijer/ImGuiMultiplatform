#include "Application.h"
#include "imgui.h"

#include "PlatformSpecific/None/None.h"
#if LOAD_SDL
#include "PlatformSpecific/SDLOpenGL/SDLOpenGL.h"
#endif
#include "PlatformSpecific/GLFWOpenGL/GLFWOpenGL.h"
#if LOAD_VULKAN
#include "PlatformSpecific/GLFWVulkan/GLFWVulkan.h"
#endif
#if defined(PLATFORM_WINDOWS) && EXPERIMENTAL
#include "PlatformSpecific/WIN32DX12/WIN32DX12.h"
#endif

namespace CF {

	Application* Application::Create(const ContextAPI& api, const Application::Specification& spec)
	{
		switch (api)
		{
		case ContextAPI::None: return new None(spec);
#if LOAD_SDL
		case ContextAPI::SDLOpenGL: return new SDLOpenGL(spec);
#endif
		case ContextAPI::GLFWOpenGL: return new GLFWOpenGL(spec);
#if LOAD_VULKAN
		case ContextAPI::GLFWVulkan: return new GLFWVulkan(spec);
#endif
#if defined(PLATFORM_WINDOWS) && EXPERIMENTAL
		case ContextAPI::WIN32DX12: return new WIN32DX12(spec);
#endif
		}

		fprintf(stderr, "Unknown API!");
		return nullptr;
	}

	void Application::RenderLayers()
	{
		if (m_MenubarCallback)
		{
			if (ImGui::BeginMainMenuBar())
			{
				m_MenubarCallback();
				ImGui::EndMainMenuBar();
			}
		}

		for (auto& layer : m_LayerStack)
			layer->OnUIRender();
	}

	void Application::SetFrameRateLimit(int limit)
	{
		if (limit >= 10)
			m_FPSLimit = 1000.f / limit;
		else if (limit == 0)
			m_FPSLimit = limit;
	}

	void Application::DestroyLayers()
	{
		for (auto& layer : m_LayerStack)
			layer->OnDetach();

		m_LayerStack.clear();
	}

}