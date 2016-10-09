#include "GhostBartScene.h"
#include "../Graphics/Graphics.h"
#include <iostream>

void GhostBartScene::SceneEnter()
{
    std::cout << "**** ENTERING GHOST BART SCENE ****" << std::endl;
    
    bart_ = LoadTexture("bart.jpg");
    if (!bart_)
        std::cout << "Where is Bart?!" << std::endl;
}

void GhostBartScene::SceneExit()
{
    std::cout << "**** EXITING GHOST BART SCENE ****" << std::endl;
}

void GhostBartScene::Update(float delta)
{
    
}

void GhostBartScene::Render()
{
    theGraphics->SetTexture(&*bart_);
    
    theGraphics->Triangle(Vertex(100, 100, 0, 0, 0, 1, 1, 1, 0.5f),
                          Vertex(100, 100 + bart_->Height(), 0, 0, 1, 1, 1, 1, 0.5f),
                          Vertex(100 + bart_->Width(), 100 + bart_->Height(), 0, 1, 1, 1, 1, 1, 0.5f));
    
    theGraphics->Triangle(Vertex(100 + bart_->Width(), 100 + bart_->Height(), 0, 1, 1, 1, 1, 1, 0.5f),
                          Vertex(100, 100, 0, 0, 0, 1, 1, 1, 0.5f),
                          Vertex(100 + bart_->Width(), 100, 0, 1, 0, 1, 1, 1, 0.5f));
}
