#pragma once
#include "Application.h"

struct GLFWwindow;

class GLFWVulkan : public Application
{
public:
	GLFWVulkan(const Application::Specification Specification);
	virtual ~GLFWVulkan();

	virtual void Run() override;

private:
	void Init();
	void Shutdown();

private:
	GLFWwindow* m_WindowHandle;
};

