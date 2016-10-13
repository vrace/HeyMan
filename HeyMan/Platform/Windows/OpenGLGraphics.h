#ifndef HEYMAN_OPENGL_GRAPHICS_H
#define HEYMAN_OPENGL_GRAPHICS_H

#include "Platform.h"

#include "../../Graphics/Graphics.h"
#include "OpenGLTexture.h"

#include <vector>

class OpenGLGraphics : public Graphics
{
public:
	OpenGLGraphics();
	~OpenGLGraphics() = default;

	virtual void Clear() override;
	virtual void SetTexture(const Texture *texture) override;
	virtual void Triangle(const Vertex &a, const Vertex &b, const Vertex &c) override;
	virtual void Commit() override;

	static void InitGraphics(HDC hdc, RECT &rc);
	static void DestroyGraphics();
	static void ResizeViewport(RECT &rc);

private:
	void Init(HDC hdc, RECT &rc);
	void Destroy();
	void Resize(RECT &rc);

private:
	HGLRC rc_;
	std::vector<Vertex> vertices_;
	const OpenGLTexture *texture_;
};

#endif
