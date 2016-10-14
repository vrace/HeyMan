#include "WelcomeScene.h"
#include "../Graphics/Graphics.h"
#include "../Application.h"

void WelcomeScene::OnEnter()
{
    bart_ = LoadTexture("bart.jpg");
    panic_ = LoadTexture("panic.jpg");
}

void WelcomeScene::OnTouch(int x, int y)
{
    
}

void WelcomeScene::Update(float delta)
{
    
}

void WelcomeScene::Render()
{
    Graphics &g = *theGraphics;
    
    bart_->Draw(g, vec2(0, 0), theApp->ScreenSize());
    panic_->Draw(g, vec2(50, 50));
}
