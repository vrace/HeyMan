#ifndef HEYMAN_GHOST_BART_SCENE_H
#define HEYMAN_GHOST_BART_SCENE_H

#include "Scene.h"
#include "../Graphics/Texture.h"

class GhostBartScene : public Scene
{
public:
    GhostBartScene() = default;
    ~GhostBartScene() = default;
    
    virtual void SceneEnter() override;
    virtual void SceneExit() override;
    virtual void Update(float delta) override;
    virtual void Render() override;
    
private:
    GhostBartScene(const GhostBartScene&) = delete;
    GhostBartScene& operator= (const GhostBartScene&) = delete;
    
private:
    std::unique_ptr<Texture> bart_;
};

#endif
