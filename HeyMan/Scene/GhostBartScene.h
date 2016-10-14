#ifndef HEYMAN_GHOST_BART_SCENE_H
#define HEYMAN_GHOST_BART_SCENE_H

#include "Scene.h"
#include "../Graphics/Texture.h"

class GhostBartScene : public Scene
{
public:
    GhostBartScene() = default;
    ~GhostBartScene() = default;
    
    virtual void OnEnter() override;
    virtual void OnExit() override;
    virtual void OnSuspend() override;
    virtual void OnResume() override;
    
    virtual void OnTouch(int x, int y) override;
    
    virtual void Update(float delta) override;
    virtual void Render() override;
    
private:
    GhostBartScene(const GhostBartScene&) = delete;
    GhostBartScene& operator= (const GhostBartScene&) = delete;
    
private:
    std::unique_ptr<Texture> bart_;
};

#endif
