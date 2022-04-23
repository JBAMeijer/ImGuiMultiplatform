#include <EntryPoint.h>
#include "imgui.h"

class WindowLayer : public Layer
{
public:

	virtual void OnUIRender() override
	{
		ImGui::Begin("Second Window");
		ImGui::Button("Button");
		ImGui::End();
	}
};

class AppLayer : public Layer
{
public:
	AppLayer(Application* app = nullptr) : m_app(app) {
		m_previous_load_new_window = false;
		m_load_new_window = false;

		m_WindowLayer = std::make_shared<WindowLayer>();
	}

	virtual void OnUIRender() override
	{
		ImGui::Begin("Hello");
		ImGui::Button("Button");

		if (m_app != nullptr)
		{
			ImGui::Checkbox("Load new imgui window", &m_load_new_window);

			if (m_load_new_window != m_previous_load_new_window)
			{
				if (m_load_new_window == true)
					m_app->PushLayer(m_WindowLayer);
				else if (m_load_new_window == false)
					m_app->PopLayer(m_WindowLayer);

				m_previous_load_new_window = m_load_new_window;
			}
		}

		ImGui::End();
	}

	Application* m_app;
	std::shared_ptr<WindowLayer> m_WindowLayer;
	bool m_load_new_window;
	bool m_previous_load_new_window;
};

Application* CreateApplication(int argc, char** argv)
{
	Application::Specification spec;
	spec.Name = "Test";
	spec.Width = 800;
	spec.Height = 400;
	Application::ContextAPI API = Application::ContextAPI::WIN32DX12;
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
	return app;
}