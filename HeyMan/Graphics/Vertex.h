#ifndef HEYMAN_VERTEX_H
#define HEYMAN_VERTEX_H

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
    Vertex(float x, float y, float z);
    Vertex(float x, float y, float z, float r, float g, float b, float a);
    Vertex(float x, float y, float z, float r, float g, float b, float a, float u, float v);
    
    unsigned Parts() const;
    bool HasColor() const;
    bool HasTexCoord() const;
    
private:
    float x_, y_, z_;
    float r_, g_, b_, a_;
    float u_, v_;
    unsigned parts_;
};

#endif
