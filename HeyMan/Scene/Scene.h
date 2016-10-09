#ifndef HEYMAN_SCENE_H
#define HEYMAN_SCENE_H

class Scene
{
public:
    Scene() = default;
    virtual ~Scene() = default;
    
    virtual void SceneEnter() = 0;
    virtual void SceneExit() = 0;
    
    virtual void Update(float delta) = 0;
    virtual void Render() = 0;
    
    // TODO: Input handler?
};

#endif
