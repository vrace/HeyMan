#import "OpenGLESTexture.h"
#import <UIKit/UIKit.h>

std::unique_ptr<Texture> LoadTexture(const std::string &name)
{
    OpenGLESTexture *texture = nullptr;
    
    NSBundle *bundle = [NSBundle mainBundle];
    NSString *path = [bundle pathForResource:[NSString stringWithUTF8String:name.c_str()]
                                      ofType:@""];
    
    if (path)
    {
        GLKTextureInfo *textureInfo = [GLKTextureLoader textureWithContentsOfFile:path
                                                                          options:nil
                                                                            error:nil];
        
        if (textureInfo)
            texture = new OpenGLESTexture(textureInfo);
    }
    
    return std::unique_ptr<Texture>(texture);
}

OpenGLESTexture::OpenGLESTexture(GLKTextureInfo *textureInfo)
: texture_(textureInfo)
{
    
}

const GLKTextureInfo* OpenGLESTexture::TextureInfo() const
{
    return texture_;
}

int OpenGLESTexture::Width() const
{
    return texture_.width;
}

int OpenGLESTexture::Height() const
{
    return texture_.height;
}
