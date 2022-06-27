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
		image = CF::LoadImage("C:\\Users\\joeym\\Pictures\\MyImage01.jpg");
		IM_ASSERT(!image.IsEmpty());
		
		image2 = image;
		image3 = image2;
	}

	virtual void OnUIRender() override
	{
		//ImGui::ShowDemoWindow();

		ImGui::Begin("ImageView");
		


		ImGui::Text("pointer = %p", image.GetTextureID());
		ImGui::Text("size = %d x %d", image.GetWidth(), image.GetWidth());
		ImGui::Image(image, ImVec2(image.GetWidth(), image.GetWidth()));
		ImGui::End();
	}

private:
	CF::Image image;
	CF::Image image2;
	CF::Image image3;
};
