#pragma once
#include "Application.h"

struct SDL_Window;
typedef void* SDL_GLContext;

class SDLOpenGL : public Application
{
public:
	SDLOpenGL(const Application::Specification& applicationSpecification);
	virtual ~SDLOpenGL();

	virtual void Run() override;

private:
	void Init();
	void Shutdown();
private:
	SDL_Window* m_WindowHandle = nullptr;
	SDL_GLContext m_Context = NULL;
};

