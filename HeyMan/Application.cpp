#include "Application.h"
#include "Graphics/Graphics.h"
#include <iostream>

bool Application::Init()
{
	std::cout << "**** APPLICATION INIT ****" << std::endl;
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
    theGraphics->Triangle(Vertex(100, 100, 0, 1, 0, 0, 1),
                          Vertex(100, 200, 0, 0, 1, 0, 1),
                          Vertex(200, 200, 0, 0, 0, 1, 1));
}
