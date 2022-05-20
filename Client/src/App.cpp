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
	spec.Width = 800;
	spec.Height = 400;
	Application::ContextAPI API = Application::ContextAPI::GLFWOpenGL;
	Application* app = Application::Create(API, spec);

	std::shared_ptr<AppLayer> appLayer = std::make_shared<AppLayer>(app);
	app->PushLayer(appLayer);
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