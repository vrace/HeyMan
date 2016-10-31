#ifndef HEYMAN_GRAPHICS_H
#define HEYMAN_GRAPHICS_H

#include <memory>
#include <functional>
#include "Vertex.h"
#include "Texture.h"

class Graphics
{
public:
	Graphics() = default;
	virtual ~Graphics() = default;

	virtual void Clear() = 0;
    virtual void SetTexture(const Texture *texture) = 0;
	virtual void Triangle(const Vertex &a, const Vertex &b, const Vertex &c) = 0;
	virtual void Commit() = 0;
    
    virtual void DrawBlock(std::function<void (Graphics &g)> drawFunc) = 0;

private:
	Graphics(const Graphics&) = delete;
	Graphics& operator= (const Graphics&) = delete;
};

extern std::unique_ptr<Graphics> theGraphics;

#endif
