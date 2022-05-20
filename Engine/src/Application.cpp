#include "Application.h"
#include "imgui.h"

#include "PlatformSpecific/None/None.h"
#include "PlatformSpecific/SDLOpenGL/SDLOpenGL.h"
#include "PlatformSpecific/GLFWOpenGL/GLFWOpenGL.h"
#include "PlatformSpecific/GLFWVulkan/GLFWVulkan.h"
#if defined(PLATFORM_WINDOWS)
#include "PlatformSpecific/WIN32DX12/WIN32DX12.h"
#endif

Application* Application::Create(const ContextAPI& api, const Application::Specification& spec)
{
	switch (api)
	{
	case ContextAPI::None: return new None(spec);
	case ContextAPI::SDLOpenGL: return new SDLOpenGL(spec);
	case ContextAPI::GLFWOpenGL: return new GLFWOpenGL(spec);
	case ContextAPI::GLFWVulkan: return new GLFWVulkan(spec);
#if defined(PLATFORM_WINDOWS)
	case ContextAPI::WIN32DX12: return new WIN32DX12(spec);
#endif
	}

	fprintf(stderr, "Unknown API!");
	return nullptr;
}

void Application::RenderLayers()
{
	// enable docking
	ImGui::DockSpaceOverViewport(ImGui::GetMainViewport(), ImGuiDockNodeFlags_None);

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

void Application::DestroyLayers()
{
	for(auto& layer : m_LayerStack)
    	layer->OnDetach();

    m_LayerStack.clear();
}