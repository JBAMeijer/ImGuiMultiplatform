#pragma once

//OpenGL	: ImTextureID = GLuint
//Vulkan	: ImTextureID = 

#include <string>
#include <memory>

#include <Application.h>
#include <imgui.h>

namespace CF
{

	class Image
	{
	private:
		struct ImageContainer
		{
			ImageContainer() {}
			ImageContainer(ImTextureID id, uint32_t width, uint32_t height) 
				: m_TextureID(id), m_Width(width), m_Height(height) {}

			operator ImTextureID() const { return m_TextureID; }

			ImTextureID m_TextureID = 0;
			uint32_t m_RefCount = 0;
			uint32_t m_Width = 0, m_Height = 0;
		};

	public:
		Image();
		Image(ImTextureID textureID, uint32_t width, uint32_t height);
		
		~Image();

		inline bool IsEmpty() const { return m_Empty; }
		
		inline ImTextureID GetTextureID() const { return m_ImageContainer->m_TextureID; }

		inline uint32_t GetWidth() const { return m_ImageContainer->m_Width; }
		inline uint32_t GetHeight() const { return m_ImageContainer->m_Height; }

		void SetNewImage(const Image& image) {}

		operator ImTextureID() const { return m_ImageContainer->m_TextureID; }
		void operator=(const Image& I);

	private:
		bool m_Empty;
		ImageContainer* m_ImageContainer;
	};

	class ImageIO
	{
	public:
		virtual Image LoadImage(const std::string& path) = 0;
		virtual bool WriteImage(const std::string& path, const Image& image) = 0;
		virtual void ClearImage(Image* image) = 0;

		static void Create(const Application::ContextAPI api);
	};
	// Free Functions
	Image LoadImage(const std::string& path);
	void WriteImage(const std::string& path, const Image& image);

	static std::unique_ptr<ImageIO> s_ImageIO;
}
