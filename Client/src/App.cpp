#include <EntryPoint.h>
#include "imgui.h"
#include "AppLayers.h"

void Mainloop()
{
	//printf("Yes\n");
}


Application* CreateApplication(int argc, char** argv)
{
	Application::Specification spec;
	spec.Name = "Test";
	spec.Width = 1280;
	spec.Height = 720;
	Application::ContextAPI API = Application::ContextAPI::GLFWOpenGL;
	Application* app = Application::Create(API, spec);

	app->PushLayer<AppLayer>();
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