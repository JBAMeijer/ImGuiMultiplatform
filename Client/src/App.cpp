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
	ApplicationSpecification spec;
	spec.Name = "Test";
	spec.Width = 800;
	spec.Height = 400;

	ContextAPI API = ContextAPI::SDLOpenGLES;
	Application* app = new Application(API, spec);
	std::shared_ptr<AppLayer> appLayer = std::make_shared<AppLayer>();
	app->PushLayer(appLayer);

	return app;
}