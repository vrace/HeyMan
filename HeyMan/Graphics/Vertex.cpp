#include "Vertex.h"

Vertex::Vertex(const vec3f &vec)
	: vec_(vec)
	, parts_(Vertex::vpVertex)
{
}

Vertex::Vertex(const vec3f &vec, const Color &color)
	: vec_(vec)
	, color_(color)
	, parts_(Vertex::vpVertex | Vertex::vpColor)
{
}

Vertex::Vertex(const vec3f &vec, const UV &uv, const Color &color)
	: vec_(vec)
	, color_(color)
	, uv_(uv)
	, parts_(Vertex::vpVertex | Vertex::vpColor | Vertex::vpTexCoord)
{
}

unsigned Vertex::Parts() const
{
    return parts_;
}

bool Vertex::HasColor() const
{
    return (parts_ & vpColor) != 0;
}

bool Vertex::HasTexCoord() const
{
    return (parts_ & vpTexCoord) != 0;
}

float* Vertex::VertexPointer() const
{
	return (float*)&vec_;
}

float* Vertex::ColorPointer() const
{
	return (float*)&color_;
}

float* Vertex::TexCoordPointer() const
{
	return (float*)&uv_;
}

int Vertex::Stride()
{
	return sizeof(Vertex);
}
