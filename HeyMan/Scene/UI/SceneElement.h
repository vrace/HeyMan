#ifndef HEYMAN_SCENE_ELEMENT_H
#define HEYMAN_SCENE_ELEMENT_H

#include "../../Types/Types.h"

#define SCENE_ELEMENT 0

class SceneElement
{
public:
    SceneElement(const std::string &id, int type);
    virtual ~SceneElement() = default;
    
    const std::string& ID() const;
    
    void SetPosition(const vec2f &pos);
    void SetSize(const vec2f &size);
    
    virtual void Update(float delta);
    virtual void Render();
    
    virtual bool HitTest(const vec2f &pos);
    
protected:
    std::string id_;
    int type_;
    vec2f position_;
    vec2f size_;
};

#endif
