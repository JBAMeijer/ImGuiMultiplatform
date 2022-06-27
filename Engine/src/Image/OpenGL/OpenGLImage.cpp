#include <Image/OpenGL/OpenGLImage.h>

#include <algorithm>
#include <iostream>

#include <GLFW/glfw3.h>

#define GL_CLAMP_TO_EDGE 0x812F

#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>

namespace CF
{
	Image OpenGLImageIO::LoadImage(const std::string& path)
	{
		int image_width = 0;
		int image_heigth = 0;
		unsigned char* imageDataTemp = stbi_load(path.c_str(), &image_width, &image_heigth, nullptr, 4);
		if (imageDataTemp == nullptr)
			return {};



		GLuint imageTexture = 0;

		glGenTextures(1, &imageTexture);
		glBindTexture(GL_TEXTURE_2D, imageTexture);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

#if defined(GL_UNPACK_ROW_LENGTH) && !defined(__EMSCRIPTEN__)
		glPixelStorei(GL_UNPACK_ROW_LENGTH, 0);
#endif
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, image_width, image_heigth, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageDataTemp);

		stbi_image_free(imageDataTemp);

		return {(void*)(intptr_t)imageTexture, (uint32_t)image_width, (uint32_t)image_heigth};
	}

	bool OpenGLImageIO::WriteImage(const std::string& path, const Image& image)
	{
		return true;//throw std::logic_error("The method or operation is not implemented.");
	}

	void OpenGLImageIO::ClearImage(Image* image)
	{
		const GLuint texID = (GLuint)image->m_TextureContainer->m_TextureID;
		glDeleteTextures(1, &texID);
	}
}

