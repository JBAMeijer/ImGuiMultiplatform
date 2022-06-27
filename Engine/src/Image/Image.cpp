#include "Image.h"
#include <Image/OpenGL/OpenGLImage.h>

#include <iostream>
#include <cassert>

namespace CF
{
	Image::Image()
		: m_Width(0), m_Height(0)
	{
		m_TextureContainer = new TextureContainer();
		m_TextureContainer->IncrementRefCount();
	}

	Image::Image(ImTextureID textureID, uint32_t width, uint32_t height)
		: m_Width(width), m_Height(height)
	{
		m_TextureContainer = new TextureContainer(textureID);
		m_TextureContainer->IncrementRefCount();
	}

	Image::~Image()
	{
		if (m_TextureContainer->m_RefCount == 1)
		{
			s_ImageIO->ClearImage(this);
			delete m_TextureContainer;
		}
		else
			m_TextureContainer->DecrementRefCount();
	}

	void Image::operator=(const Image& D)
	{
		m_Width = D.m_Height;
		m_Height = D.m_Height;

		delete m_TextureContainer;
		m_TextureContainer = nullptr;

		m_TextureContainer = D.m_TextureContainer;
		m_TextureContainer->IncrementRefCount();
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