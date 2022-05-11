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
		ImGui::Text("Application average %.3f ms/frame (%.1f FPS)", 1000.0f / ImGui::GetIO().Framerate, ImGui::GetIO().Framerate);
		ImGui::End();
	}

	Application* m_app;
	std::shared_ptr<WindowLayer> m_WindowLayer;
	bool m_load_new_window;
	bool m_previous_load_new_window;
};
