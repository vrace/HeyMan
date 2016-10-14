#include "Texture.h"
#include "Graphics.h"

void Texture::Draw(Graphics &g, const vec2 &origin, const vec2 &size)
{
    Vertex topLeft = Vertex(origin.x, origin.y, 0, 0, 0);
    Vertex topRight = Vertex(origin.x + size.x, origin.y, 0, 1, 0);
    Vertex bottomLeft = Vertex(origin.x, origin.y + size.y, 0, 0, 1);
    Vertex bottomRight = Vertex(origin.x + size.x, origin.y + size.y, 0, 1, 1);
    
    g.SetTexture(this);
    g.Triangle(topLeft, bottomLeft, bottomRight);
    g.Triangle(bottomRight, topLeft, topRight);
}

void Texture::Draw(class Graphics &g, const vec2 &origin)
{
    Draw(g, origin, vec2(Width(), Height()));
}
