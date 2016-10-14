#ifndef HEYMAN_WELCOME_SCENE_H
#define HEYMAN_WELCOME_SCENE_H

#include "Scene.h"

class WelcomeScene : public Scene
{
public:
    WelcomeScene() = default;
    ~WelcomeScene() = default;
    
    virtual void OnEnter() override;
    virtual void OnExit() override;
    virtual void OnSuspend() override;
    virtual void OnResume() override;
    
    virtual void Update(float delta) override;
    virtual void Render() override;
    
private:
    
};

#endif
