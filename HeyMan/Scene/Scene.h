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
    
    virtual void OnTouch(int x, int y);
    
    virtual void Update(float delta) = 0;
    virtual void Render() = 0;
};

#endif
