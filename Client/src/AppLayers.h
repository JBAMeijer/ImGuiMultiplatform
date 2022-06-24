#include "Layer.h"

class AppLayer : public CF::Layer
{
public:
	AppLayer() {
	}

	virtual void OnUIRender() override
	{
		//ImGui::ShowDemoWindow();

		ImGui::Begin("ImageView");

		ImGui::Image()

		ImGui::End();
	}
};
