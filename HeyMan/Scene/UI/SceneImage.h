#ifndef HEYMAN_SCENE_IMAGE_H
#define HEYMAN_SCENE_IMAGE_H

#include "SceneElement.h"
#include "SceneElementTexturable.h"
#include "../../Graphics/Texture.h"

#define SCENE_ELEMENT_IMAGE 2

class SceneImage
: public SceneElement
, public SceneElementTexturable
{
public:
    SceneImage(const std::string &id);
    
    void SetTexture(const std::string &image);
    
    void Render();
    
protected:
    std::unique_ptr<Texture> texture_;
};

#endif
