#pragma once
#include <string>
#include <functional>
#include <memory>

#include "Layer.h"

struct ApplicationSpecification
{
	std::string Name = "ImGuiApp";
	uint32_t Width = 400;
	uint32_t Height = 200;
};

enum class ContextAPI
{
	SDLOpenGLES = 0,
	GLFWVulkan
};

class GenericContext;

class Application
{
public:
	Application(const ContextAPI& api, const ApplicationSpecification& applicationSpecification);
	
	~Application();

	void Run();
		//virtual void SetMenubarCallback(const std::function<void()>& menubarCallback) = 0;

	void PushLayer(const std::shared_ptr<Layer>& layer);

	void Close();

	static Application* Create(const ContextAPI&, const ApplicationSpecification&);

private:
	GenericContext* m_context;
};

Application* CreateApplication(int argc, char** argv);