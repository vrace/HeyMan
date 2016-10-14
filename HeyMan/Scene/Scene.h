#ifndef HEYMAN_SCENE_H
#define HEYMAN_SCENE_H

#include "../Types/Types.h"

class Scene
{
public:
    Scene() = default;
    virtual ~Scene() = default;
    
    virtual void OnEnter() = 0;
    virtual void OnExit() = 0;
    virtual void OnSuspend() = 0;
    virtual void OnResume() = 0;
    
    virtual void OnTouch(int x, int y) = 0;
    
    virtual void Update(float delta) = 0;
    virtual void Render() = 0;
};

#endif
