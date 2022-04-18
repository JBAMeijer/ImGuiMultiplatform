#include <EntryPoint.h>
#include "imgui.h"


class AppLayer : public Layer
{
public:
	virtual void OnUIRender() override
	{
		ImGui::Begin("Hello");
		ImGui::Button("Button");
		ImGui::End();
	}
};

Application* CreateApplication(int argc, char** argv)
{
	Application::Specification spec;
	spec.Name = "Test";
	spec.Width = 800;
	spec.Height = 400;
	Application::ContextAPI API = Application::ContextAPI::WIN32DX11;
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
	return app;
}