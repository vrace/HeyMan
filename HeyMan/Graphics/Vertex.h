#ifndef HEYMAN_VERTEX_H
#define HEYMAN_VERTEX_H

#include "../Types/Types.h"

class Vertex
{
public:
    enum VertexParts
    {
        vpVertex = 0,
        vpColor = 1,
        vpTexCoord = 2,
    };
    
    Vertex() = delete;
    Vertex(const vec3f &vec);
    Vertex(const vec3f &vec, const Color &color);
    Vertex(const vec3f &vec, const UV &uv, const Color &color = Color());
    
    unsigned Parts() const;
    bool HasColor() const;
    bool HasTexCoord() const;

	float* VertexPointer() const;
	float* ColorPointer() const;
	float* TexCoordPointer() const;
	static int Stride();
    
private:
	vec3f vec_;
	Color color_;
	UV uv_;
    unsigned parts_;
};

#endif
