#include "Layer.h"

#include <iostream>

#include <Image/Image.h>

class AppLayer : public CF::Layer
{
public:
	AppLayer() {
		//image = std::make_unique<CF::Image>(CF::LoadImage(R"(C:\Users\Joey\Pictures\MyImage01.jpg)"));
	}

	~AppLayer()
	{
	}

	virtual void OnUIRender() override
	{
		//ImGui::ShowDemoWindow();

		ImGui::Begin("ImageView");
		
		CF::Image image = CF::LoadImage(R"(C:\Users\Joey\Pictures\MyImage01.jpg)");
		//nt height = image.m_Height;

		ImGui::Text("pointer = %p", (int)image.m_TextureID);
		ImGui::Text("size = %d x %d", image.m_Width, image.m_Height);
		//std::cout << "Datapointer: " << image->m_DataPointer << ", Width: " << image->m_Width << ", Height: " << image->m_Height << '\n';

		ImGui::Image(image, { (float)image.m_Width, (float)image.m_Height });

		ImGui::End();
	}

private:
	//std::unique_ptr<CF::Image> image;
};
