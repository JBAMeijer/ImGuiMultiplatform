#pragma once
#include "Application.h"
#include <windows.h>

class WIN32DX11 : public Application
{
public:
	WIN32DX11(const Application::Specification specification);
	~WIN32DX11();

	void Run() override;

private:
	void Init();
	void Shutdown();

private:
	HWND m_WindowHandle;
	WNDCLASSEX m_wc;
};

