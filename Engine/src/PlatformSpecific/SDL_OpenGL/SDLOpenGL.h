#pragma once

//#include "Application.h"
#include "GenericContext.h"
#include <functional>
#include <memory>

#include "layer.h"

struct ApplicationSpecification;
typedef void* SDL_GLContext;
struct SDL_Window;

class SDL_OpenGL : public GenericContext
{
public:
	SDL_OpenGL(const ApplicationSpecification& applicationSpecification);
	~SDL_OpenGL();

	void Run();
	void SetMenubarCallback(const std::function<void() >& menubarCallback);

	void PushLayer(const std::shared_ptr<Layer>& layer);

	void Close();
private:
	virtual void Init();
	virtual void Shutdown();
private:
	const ApplicationSpecification& m_Specification;
	SDL_Window* m_WindowHandle = nullptr;
	SDL_GLContext m_Context = NULL;
	bool m_Running = false;

	std::vector<std::shared_ptr<Layer>> m_LayerStack;
	std::function<void()> m_MenubarCallback;
};

