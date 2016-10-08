#include "Vertex.h"

Vertex::Vertex(float x, float y, float z)
: x_(x), y_(y), z_(z)
, r_(1), g_(1), b_(1), a_(1)
, u_(0), v_(0)
, parts_(Vertex::vpVertex)
{
}

Vertex::Vertex(float x, float y, float z, float r, float g, float b, float a)
: x_(x), y_(y), z_(z)
, r_(r), g_(g), b_(b), a_(a)
, u_(0), v_(0)
, parts_(Vertex::vpVertex | Vertex::vpColor)
{
}

Vertex::Vertex(float x, float y, float z, float r, float g, float b, float a, float u, float v)
: x_(x), y_(y), z_(z)
, r_(r), g_(g), b_(b), a_(a)
, u_(v), v_(v)
, parts_(Vertex::vpVertex | Vertex::vpColor | Vertex::vpTexCoord)
{
}

unsigned Vertex::Parts() const
{
    return parts_;
}

bool Vertex::HasColor() const
{
    return parts_ & vpColor;
}

bool Vertex::HasTexCoord() const
{
    return parts_ & vpTexCoord;
}
