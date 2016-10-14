#include "GhostBartScene.h"
#include "../Graphics/Graphics.h"
#include "../Camera/Camera.h"
#include <iostream>

void GhostBartScene::OnEnter()
{
    std::cout << "**** ENTERING GHOST BART SCENE ****" << std::endl;
    
    bart_ = LoadTexture("bart.jpg");
    if (!bart_)
        std::cout << "Where is Bart?!" << std::endl;
    
    CameraCaptureStart(nullptr);
}

void GhostBartScene::OnExit()
{
    std::cout << "**** EXITING GHOST BART SCENE ****" << std::endl;
    
    CameraCaptureStop();
}

void GhostBartScene::OnSuspend()
{
    std::cout << "**** SUSPENDING BART SCENE ****" << std::endl;
}

void GhostBartScene::OnResume()
{
    std::cout << "**** RESUME BART SCENE ****" << std::endl;
}

void GhostBartScene::OnTouch(int x, int y)
{
    std::cout << "Doh (" << x << ", " << y << ")" << std::endl;
}

void GhostBartScene::Update(float delta)
{
    
}

void GhostBartScene::Render()
{
    bart_->Draw(*theGraphics, vec2(50, 50));
}
