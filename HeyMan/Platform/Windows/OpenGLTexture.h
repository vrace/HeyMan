#ifndef HEYMAN_OPENGL_TEXTURE_H
#define HEYMAN_OPENGL_TEXTURE_H

#include "Platform.h"
#include "../../Graphics/Texture.h"

class OpenGLTexture : public Texture
{
public:
	OpenGLTexture(GLuint id, int width, int height);
	~OpenGLTexture();

	GLuint TextureID() const;
	virtual int Width() const override;
	virtual int Height() const override;

private:
	OpenGLTexture() = delete;
	OpenGLTexture(const OpenGLTexture&) = delete;
	OpenGLTexture& operator= (const OpenGLTexture&) = delete;

private:
	GLuint id_;
	int width_;
	int height_;
};

#endif
