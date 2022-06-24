#pragma once

//OpenGL	: ImTextureID = GLuint
//DirectX9  : ImTextureID = LPDIRECT3DTEXTURE9
//DirectX11 : ImTextureID = ID3D11ShaderResourceView* 
//DirectX12 : ImTextureID = D3D12_GPU_DESCRIPTOR_HANDLE
//Vulkan	: ImTextureID = 

#include <string>
#include <memory>

namespace CF
{

	class Image
	{
	public:
		virtual ~Image() = default;

		virtual uint32_t GetWidth() {};
		virtual uint32_t GetHeight() {};

		virtual unsigned char* GetDataPointer() {};
	
		virtual void SetNewImage(const Image& image) {};

		virtual void operator=(const Image& image) {};
	};

	// Static Functions
	static Image LoadImage(const std::string& path);
	//static void WriteImage(const std::string& path, const Image& image);
}
