#ifndef HEYMAN_SCENE_H
#define HEYMAN_SCENE_H

#include "../Types/Types.h"

class Scene
{
public:
    Scene() = default;
    virtual ~Scene() = default;
    
    virtual void OnEnter();
    virtual void OnExit();
    virtual void OnSuspend();
    virtual void OnResume();
    
    virtual void OnTouchBegin(const vec2 &pt);
    virtual void OnTouchMove(const vec2 &pt);
    virtual void OnTouchEnd(const vec2 &pt);
    
    virtual void Update(float delta);
    virtual void Render();
};

#endif
