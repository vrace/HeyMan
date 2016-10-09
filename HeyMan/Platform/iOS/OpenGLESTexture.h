#ifndef HEYMAN_OPENGLES_TEXTURE_H
#define HEYMAN_OPENGLES_TEXTURE_H

#import "../../Graphics/Texture.h"
#import <GLKit/GLKit.h>

class OpenGLESTexture : public Texture
{
public:
    OpenGLESTexture(GLKTextureInfo *textureInfo);
    ~OpenGLESTexture() = default;
    
    const GLKTextureInfo *TextureInfo() const;
    
    virtual int Width() const override;
    virtual int Height() const override;
    
private:
    GLKTextureInfo *texture_;
};

#endif
