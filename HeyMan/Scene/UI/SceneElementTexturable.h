#ifndef HEYMAN_SCENE_ELEMENT_TEXTURABLE_H
#define HEYMAN_SCENE_ELEMENT_TEXTURABLE_H

#include <string>

class SceneElementTexturable
{
public:
    virtual void SetTexture(const std::string &name) = 0;
};

#endif
