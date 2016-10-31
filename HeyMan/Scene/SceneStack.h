#ifndef HEYMAN_SCENE_STACK_H
#define HEYMAN_SCENE_STACK_H

#include <vector>
#include <functional>
#include "Scene.h"

enum PushSceneMethod
{
    psmSuspend = 0,
    psmUpdate = 1,
    psmRender = 2,
    psmUpdateAndRender = psmUpdate | psmRender,
};

class SceneStackItem
{
public:
    SceneStackItem(Scene *scene, PushSceneMethod method);
    
    Scene* GetScene() const;
    PushSceneMethod GetMethod() const;
    
private:
    Scene *scene_;
    PushSceneMethod method_;
};

class SceneStack
{
public:
    SceneStack();
    virtual ~SceneStack() = default;
    
    bool PushScene(Scene* scene, PushSceneMethod method = psmSuspend);
    void PopScene();
    
    void TouchBegin(const vec2 &pt);
    void TouchMove(const vec2 &pt);
    void TouchEnd(const vec2 &pt);
    
    void Update(float delta);
    void Render();
    
private:
    void WalkStack(std::function<void (const SceneStackItem&)> func) const;
    
private:
    Scene *current_;
    std::vector<SceneStackItem> scenes_;
};

#endif
