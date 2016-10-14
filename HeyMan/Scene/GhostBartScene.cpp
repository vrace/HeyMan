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

void GhostBartScene::Update(float delta)
{
    
}

void GhostBartScene::Render()
{
    theGraphics->SetTexture(&*bart_);
    
    theGraphics->Triangle(Vertex(100, 100, 0, 0, 0),
                          Vertex(100, 100 + bart_->Height(), 0, 0, 1),
                          Vertex(100 + bart_->Width(), 100 + bart_->Height(), 0, 1, 1));
    
    theGraphics->Triangle(Vertex(100 + bart_->Width(), 100 + bart_->Height(), 0, 1, 1),
                          Vertex(100, 100, 0, 0, 0, 1),
                          Vertex(100 + bart_->Width(), 100, 0, 1, 0));
}
