#pragma once
#include "Application.h"

struct GLFWwindow;

class GLFWOpenGL : public Application
{
public:
    GLFWOpenGL(const Application::Specification Specification);
    virtual ~GLFWOpenGL();

    virtual void Run() override;

private:
    void Init();
    void Shutdown();

private:
    GLFWwindow* m_WindowHandle = nullptr;
};