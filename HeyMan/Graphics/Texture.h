#ifndef HEYMAN_TEXTURE
#define HEYMAN_TEXTURE

#include "../Types/Types.h"
#include <memory>
#include <string>

class Texture
{
public:
    Texture() = default;
    virtual ~Texture() = default;
    
    virtual int Width() const = 0;
    virtual int Height() const = 0;
    
    void Draw(class Graphics &g, const vec2 &origin);
    void Draw(class Graphics &g, const vec2 &origin, const vec2 &size);
};

extern std::unique_ptr<Texture> LoadTexture(const std::string &name);

#endif
