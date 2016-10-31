#ifndef HEYMAN_ELEMENT_UI_SCENE_H
#define HEYMAN_ELEMENT_UI_SCENE_H

#include "Scene.h"
#include "UI/SceneCanvas.h"
#include <string>

class ElementUIScene : public Scene
{
public:
    void LoadFromFile(const std::string &file);
    
    virtual void Update(float delta) override;
    virtual void Render() override;
    
    virtual void OnTouchEnd(const vec2 &pt) override;
    
    virtual void OnTouchElement(SceneElement &element);
    
private:
    std::unique_ptr<SceneCanvas> canvas_;
};

#endif
