#pragma once
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
		SDLOpenGLES,
		GLFWVulkan,
		WIN32DX11
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

	virtual void Close() { m_Running = false; }
	
	template<typename T>
	void PushLayer()
	{
		static_assert(std::is_base_of<Layer, T>::value, "Pushed type is not subclass of Layer!");
		m_LayerStack.emplace_back(std::make_shared<T>())->OnAttach();
	}
	void PushLayer(const std::shared_ptr<Layer>& layer)
	{
		m_LayerStack.emplace_back(layer); 
		layer->OnAttach();
	}

	static Application* Create(const ContextAPI&, const Specification&);

protected:
	bool m_Running = false;
	const Specification& m_Specification;
	std::vector<std::shared_ptr<Layer>> m_LayerStack;

	std::function<void()> m_MenubarCallback;
};

Application* CreateApplication(int argc, char** argv);