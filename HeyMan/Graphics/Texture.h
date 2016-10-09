#ifndef HEYMAN_TEXTURE
#define HEYMAN_TEXTURE

#include <memory>
#include <string>

class Texture
{
public:
    Texture() = default;
    virtual ~Texture() = default;
    
    virtual int Width() const = 0;
    virtual int Height() const = 0;
};

extern std::unique_ptr<Texture> LoadTexture(const std::string &name);

#endif
