#pragma once
#include <Image/Image.h>

using GLuint = unsigned int;

namespace CF
{
	class OpenGLImageIO : public ImageIO
	{
	public:
		Image LoadImage(const std::string& path) override;
		bool WriteImage(const std::string& path, const Image& image) override;

		void ClearImage(Image* image) override;
	};
}

