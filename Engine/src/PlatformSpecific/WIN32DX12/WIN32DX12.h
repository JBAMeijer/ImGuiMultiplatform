#pragma once
#include "Application.h"
#include <windows.h>

class WIN32DX12 : public Application
{
public:
	WIN32DX12(const Application::Specification& specification);
	virtual ~WIN32DX12();

	void Run() override;

private:
	void Init();
	void Shutdown();

private:
	HWND m_WindowHandle;
	WNDCLASSEX m_wc;
};

