#include "Application.h"
#include "Graphics/Graphics.h"
#include <iostream>

bool Application::Init()
{
	std::cout << "**** APPLICATION INIT ****" << std::endl;
    
    bart_ = LoadTexture("bart.jpg");
    if (!bart_)
        std::cout << "Where is bart?!" << std::endl;
    
	return true;
}

void Application::Destroy()
{
	std::cout << "**** APPLICATION DESTROY ****" << std::endl;
}

void Application::Update(float delta)
{
}

void Application::Render()
{
    theGraphics->SetTexture(&*bart_);
    
    theGraphics->Triangle(Vertex(100, 100, 0, 0, 0),
                          Vertex(100, 100 + bart_->Height(), 0, 0, 1),
                          Vertex(100 + bart_->Width(), 100 + bart_->Height(), 0, 1, 1));
    
    theGraphics->Triangle(Vertex(100 + bart_->Width(), 100 + bart_->Height(), 0, 1, 1),
                          Vertex(100, 100, 0, 0, 0),
                          Vertex(100 + bart_->Width(), 100, 0, 1, 0));
}
