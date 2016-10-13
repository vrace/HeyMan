#include "OpenGLTexture.h"
#include <memory>

std::unique_ptr<Texture> LoadTexture(const std::string &name)
{
	std::unique_ptr<Texture> texture;

	auto resourceName = std::string("Resources/") + name;

	auto image = std::unique_ptr<Gdiplus::Image>(Gdiplus::Image::FromFile((const WCHAR*)_bstr_t(resourceName.c_str())));
	if (image)
	{
		auto bitmap = std::make_unique<Gdiplus::Bitmap>(image->GetWidth(), image->GetHeight(), PixelFormat24bppRGB);
		{
			auto g = std::unique_ptr<Gdiplus::Graphics>(Gdiplus::Graphics::FromImage(&*bitmap));
			g->DrawImage(&*image, 0, 0, image->GetWidth(), image->GetHeight());
		}
		image.reset();

		Gdiplus::Rect rc(0, 0, bitmap->GetWidth(), bitmap->GetHeight());
		Gdiplus::BitmapData data;
		if (bitmap->LockBits(&rc, Gdiplus::ImageLockModeRead, PixelFormat24bppRGB, &data) == Gdiplus::Ok)
		{
			GLuint id;
			glGenTextures(1, &id);
			glBindTexture(GL_TEXTURE_2D, id);
			glTexImage2D(GL_TEXTURE_2D, 0, 3, data.Width, data.Height, 0, GL_RGB, GL_UNSIGNED_BYTE, data.Scan0);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

			texture = std::make_unique<OpenGLTexture>(id, data.Width, data.Height);

			bitmap->UnlockBits(&data);
		}
	}

	return texture;
}

OpenGLTexture::OpenGLTexture(GLuint id, int width, int height)
	: id_(id)
	, width_(width)
	, height_(height)
{

}

OpenGLTexture::~OpenGLTexture()
{
	glDeleteTextures(1, &id_);
}

GLuint OpenGLTexture::TextureID() const
{
	return id_;
}

int OpenGLTexture::Width() const
{
	return width_;
}

int OpenGLTexture::Height() const
{
	return height_;
}
