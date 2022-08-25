#include <EntryPoint.h>
#include "imgui.h"
#include "AppLayers.h"

void Mainloop()
{
	//printf("Yes\n");
}


CF::Application* CF::CreateApplication(int argc, char** argv)
{
	CF::Application::Specification spec;
	spec.Name = "Test";
	spec.Width = 1280;
	spec.Height = 720;
	CF::Application::ContextAPI API = CF::Application::ContextAPI::GLFWOpenGL;
	CF::Application* app = CF::Application::Create(API, spec);

	app->PushLayer(AppLayer());
	//app->PushLayer<AppLayer>();
	app->SetMenubarCallback([app]()
	{
		if (ImGui::BeginMenu("File"))
		{
			if (ImGui::MenuItem("Exit"))
			{
				app->Close();
			}
			ImGui::EndMenu();
		}
	});

	app->SetMainloopCallback(Mainloop);

	return app;
}