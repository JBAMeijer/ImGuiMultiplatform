#pragma once
#include "Application.h"

extern CF::Application* CF::CreateApplication(int argc, char** argv);
bool g_ApplicationRunning = true;

namespace CF {

	int EntryPoint(int argc, char** argv)
	{
		while (g_ApplicationRunning)
		{
			Application* app = CreateApplication(argc, argv);
			app->Run();
			delete app;
		}

		return 0;
	}

}

#if defined(CF_DIST) && defined(PLATFORM_WINDOWS)

#include <Windows.h>

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)
{
	return CF::EntryPoint(__argc, __argv);
}

#elif defined(CF_DIST)

int main(int argc, char** argv)
{
	return CF::EntryPoint(argc, argv);
}

#endif