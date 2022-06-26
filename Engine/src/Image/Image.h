#pragma once

//OpenGL	: ImTextureID = GLuint
//DirectX9  : ImTextureID = LPDIRECT3DTEXTURE9
//DirectX11 : ImTextureID = ID3D11ShaderResourceView* 
//DirectX12 : ImTextureID = D3D12_GPU_DESCRIPTOR_HANDLE
//Vulkan	: ImTextureID = 

#include <string>
#include <memory>

#include <Application.h>
#include <imgui.h>

namespace CF
{
	struct Image
	{
	public:
		Image();
		Image(void* textureID, uint32_t width, uint32_t height, unsigned char* dataPointer);
		
		~Image();

		uint32_t m_Width, m_Height;
		unsigned char* m_DataPointer;
		void* m_TextureID;
	
		void SetNewImage(const Image& image) {}

		operator ImTextureID() const { return nullptr; }
		void operator=(const Image& D);

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
