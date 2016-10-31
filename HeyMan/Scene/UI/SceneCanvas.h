#ifndef HEYMAN_SCENE_CANVAS_H
#define HEYMAN_SCENE_CANVAS_H

#include "SceneElement.h"
#include <vector>

#define SCENE_ELEMENT_CANVAS 1

class SceneCanvas : public SceneElement
{
public:
    SceneCanvas(int width, int height);
    virtual ~SceneCanvas();
    
    void AddComponent(SceneElement *component);
    
    virtual void Update(float delta) override;
    virtual void Render() override;
    
    SceneElement* CanvasHitTest(const vec2f &pt);
    
protected:
    std::vector<SceneElement*> components_;
};

#endif
