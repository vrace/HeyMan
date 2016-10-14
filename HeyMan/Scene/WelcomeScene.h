#ifndef HEYMAN_WELCOME_SCENE_H
#define HEYMAN_WELCOME_SCENE_H

#include "Scene.h"
#include "../Graphics/Texture.h"

class WelcomeScene : public Scene
{
public:
    WelcomeScene() = default;
    ~WelcomeScene() = default;
    
    virtual void OnEnter() override;
    virtual void OnTouch(int x, int y) override;
    
    virtual void Update(float delta) override;
    virtual void Render() override;
    
private:
    std::unique_ptr<Texture> bart_;
    std::unique_ptr<Texture> panic_;
};

#endif
