#include "Image.h"
#include <Image/OpenGL/OpenGLImage.h>

#include <iostream>
#include <cassert>

namespace CF
{
	Image::Image()
		: m_Empty(true)
	{
		m_ImageContainer = new ImageContainer();
		m_ImageContainer->m_RefCount++;
	}

	Image::Image(ImTextureID textureID, uint32_t width, uint32_t height)
		: m_Empty(false)
	{
		m_ImageContainer = new ImageContainer(textureID, width, height);
		m_ImageContainer->m_RefCount++;
	}

	Image::~Image()
	{
		if (m_ImageContainer->m_RefCount == 1)
		{
			s_ImageIO->ClearImage(this);
			delete m_ImageContainer;
		}
		else
			m_ImageContainer->m_RefCount--;
	}

	void Image::operator=(const Image& D)
	{
		m_Empty = D.IsEmpty();

		m_ImageContainer->m_Width = D.m_ImageContainer->m_Width;
		m_ImageContainer->m_Height = D.m_ImageContainer->m_Height;

		delete m_ImageContainer;
		m_ImageContainer = nullptr;

		m_ImageContainer = D.m_ImageContainer;
		m_ImageContainer->m_RefCount++;
	}

	void ImageIO::Create(const Application::ContextAPI api)
	{
		switch (api)
		{
		case Application::ContextAPI::GLFWOpenGL:
			s_ImageIO = std::make_unique<OpenGLImageIO>();
			break;
		default:
			assert(0);
			std::cout << "Unknown Context\n";
			break;
		}
	}

	Image LoadImage(const std::string& path)
	{
		return s_ImageIO->LoadImage(path);
	}

	void WriteImage(const std::string& path, const Image& image)
	{
		s_ImageIO->WriteImage(path, image);
	}
}