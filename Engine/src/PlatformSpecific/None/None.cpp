#include "None.h"
#include <imgui.h>

#include <future>
#include <thread>
#include <iostream>

extern bool g_ApplicationRunning;

None::None(const Application::Specification& applicationSpecification)
	: Application(applicationSpecification)
{
	Init();
}

None::~None()
{
	Shutdown();
}

void None::Run()
{
	m_Running = true;

	auto future = std::async(std::launch::async, [this]() {
		Close();
	});

	while (m_Running)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));

		ImGui::NewFrame();

		RenderLayers();

		ImGui::Render();
	}
}

void None::Close()
{
	printf("[CORE]Press enter to close!");
	std::cin.get();
	m_Running = false;
}

void None::Init()
{
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();

	// build atlas
	unsigned char* tex_pixels = NULL;
	int tex_w, tex_h;
	io.Fonts->GetTexDataAsRGBA32(&tex_pixels, &tex_w, &tex_h);
	io.DisplaySize = ImVec2(m_Specification.Width, m_Specification.Height);
}

void None::Shutdown()
{
	DestroyLayers();

	ImGui::DestroyContext();

	g_ApplicationRunning = false;
}
