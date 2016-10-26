#include "Texture.h"
#include "Graphics.h"

void Texture::Draw(Graphics &g, const vec2 &origin, const vec2 &size)
{
	float left = (float)origin.x;
	float right = (float)(origin.x + size.x);
	float top = (float)origin.y;
	float bottom = (float)(origin.y + size.y);

    Vertex topLeft = Vertex(vec3f(left, top), UV(0, 0));
    Vertex topRight = Vertex(vec3f(right, top), UV(1, 0));
    Vertex bottomLeft = Vertex(vec3f(left, bottom), UV(0, 1));
    Vertex bottomRight = Vertex(vec3f(right, bottom), UV(1, 1));
    
    g.SetTexture(this);
    g.Triangle(topLeft, bottomLeft, bottomRight);
    g.Triangle(bottomRight, topLeft, topRight);
}

void Texture::Draw(class Graphics &g, const vec2 &origin)
{
    Draw(g, origin, vec2(Width(), Height()));
}
