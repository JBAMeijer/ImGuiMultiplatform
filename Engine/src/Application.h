#pragma once
#include <Base.h>

#include <string>
#include <functional>
#include <memory>

#include "Layer.h"


class Application
{
public:
	enum class ContextAPI
	{
		None = 0,
#if defined(LOAD_SDL)
		SDLOpenGL,
#endif
		GLFWOpenGL,
#if defined(LOAD_VULKAN)
		GLFWVulkan,
#endif
#if defined(PLATFORM_WINDOWS)
		WIN32DX12,
#endif
	};

	struct Specification
	{
		std::string Name = "App";
		uint32_t Width = 400;
		uint32_t Height = 200;
	};

public:
	Application(const Specification& applicationSpecification) : m_Specification(applicationSpecification) {}
	
	virtual ~Application() = default;
	virtual void Run() = 0;
	virtual void SetMenubarCallback(const std::function<void()>& menubarCallback) { m_MenubarCallback = menubarCallback; };
	virtual void SetMainloopCallback(const std::function<void()>& mainloopCallback) { m_MainloopCallback = mainloopCallback; };
	void SetFrameRateLimit(int limit);

	virtual void Close() { m_Running = false; }
	
	template<typename T>
	Layer* PushLayer()
	{
		static_assert(std::is_base_of<Layer, T>::value, "Pushed type is not subclass of Layer!");
		Layer* layer = m_LayerStack.emplace_back(std::make_unique<T>()).get();
		layer->OnAttach();
		return layer;
	}

	virtual Layer* PushLayer(Layer&& layer)
	{
		Layer* Tlayer = m_LayerStack.emplace_back(std::make_unique<Layer>(layer)).get();
		Tlayer->OnAttach();
		return Tlayer;
	}

	/*virtual void PopLayer(const std::unique_ptr<Layer>&& layer)
	{
		auto it = std::find(m_LayerStack.begin(), m_LayerStack.end(), layer);
		if (it != m_LayerStack.end())
			m_LayerStack.erase(it);
	}*/

	static Application* Create(const ContextAPI&, const Specification&);

protected:
	bool m_renderingAllowed = true;
	bool m_Running = false;
	float m_FPSLimit = 0.f;
	const Specification& m_Specification;
	std::function<void()> m_MainloopCallback;

protected:
	virtual void RenderLayers();
	void DestroyLayers();

private:
	std::vector<std::unique_ptr<Layer>> m_LayerStack;
	std::function<void()> m_MenubarCallback;

private:
	virtual void Init() = 0;
	virtual void Shutdown() = 0;
};

Application* CreateApplication(int argc, char** argv);