#include "WelcomeScene.h"
#include "../Graphics/Graphics.h"
#include "../Application.h"
#include <assert.h>

void WelcomeScene::OnEnter()
{
    LoadFromFile("Welcome.ui");
}

void WelcomeScene::OnTouchElement(SceneElement &element)
{
    if (element.ID() == "panic")
    {
        theApp->PushScene(asScan);
    }
}
