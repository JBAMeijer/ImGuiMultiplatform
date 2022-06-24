#pragma once
#include <Image/Image.h>

typedef unsigned int GLuint;

namespace CF
{
	class OpenGLImage : public Image
	{
	public:
		OpenGLImage() { Load(); };
		virtual ~OpenGLImage() { Clear(); };

		virtual uint32_t GetWidth() const { m_Width; };
		virtual uint32_t GetHeight() const { m_Height; };

		virtual unsigned char* GetDataPointer() const { m_DataPointer; };

		virtual void SetNewImage(const Image& image);

		virtual void operator=(const Image& image);

	private:
		void Load();
		void Clear();

	private:
		uint32_t m_Width, m_Height;
		unsigned char* m_DataPointer;
		GLuint* m_TextureID;
	};
}

