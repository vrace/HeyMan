#ifndef HEYMAN_WELCOME_SCENE_H
#define HEYMAN_WELCOME_SCENE_H

#include "ElementUIScene.h"

class WelcomeScene : public ElementUIScene
{
public:
    virtual void OnEnter() override;
    virtual void OnTouchElement(SceneElement &element) override;
};

#endif
