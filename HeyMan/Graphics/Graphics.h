#ifndef HEYMAN_GRAPHICS_H
#define HEYMAN_GRAPHICS_H

#include <memory>

class Graphics
{
public:
	Graphics() = default;
	virtual ~Graphics() = default;

	virtual void Clear() = 0;
	virtual void Triangle() = 0;
	virtual void Commit() = 0;

private:
	Graphics(const Graphics&) = delete;
	Graphics& operator= (const Graphics&) = delete;
};

extern std::unique_ptr<Graphics> theGraphics;

#endif
