#pragma once

#include "Layer.h"
//#include "Helpers.h"

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

	virtual void OnAttach() override
	{
		//bool ret = LoadTextureFromFile("C:\\Users\\joeym\\Pictures\\MyImage01.jpg", &my_image_texture, &my_image_width, &my_image_height);
		//IM_ASSERT(ret);
		image = CF::LoadImage("C:\\Users\\joeym\\Pictures\\MyImage01.jpg");
		image2 = image;
		image3 = image2;
	}

	virtual void OnUIRender() override
	{
		//ImGui::ShowDemoWindow();

		ImGui::Begin("ImageView");
		


		ImGui::Text("pointer = %p", image.m_TextureContainer->m_TextureID);
		ImGui::Text("size = %d x %d", image.m_Width, image.m_Height);
		ImGui::Image(image, ImVec2(image.m_Width, image.m_Height));
		ImGui::End();
	}

private:
	CF::Image image;
	CF::Image image2;
	CF::Image image3;
};
