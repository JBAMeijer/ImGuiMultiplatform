#include "Image.h"
#include <Image/OpenGL/OpenGLImage.h>

#include <iostream>
#include <cassert>

namespace CF
{
	Image::Image()
		: m_TextureID(nullptr), m_Width(0), m_Height(0), m_DataPointer(nullptr)
	{

	}

	Image::Image(void* textureID, uint32_t width, uint32_t height, unsigned char* dataPointer)
		: m_TextureID(textureID), m_Width(width), m_Height(height), m_DataPointer(dataPointer)
	{

	}

	Image::~Image()
	{
		s_ImageIO->ClearImage(this);

		std::cout << "Deleted pointer\n";
	}

	void Image::operator=(const Image& D)
	{
		m_Width = D.m_Height;
		m_Height = D.m_Height;
		m_TextureID = D.m_TextureID;

		m_DataPointer = new unsigned char[m_Height * m_Width];
		std::copy(D.m_DataPointer, D.m_DataPointer + (m_Height * m_Width), m_DataPointer);
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