#include "Application.h"
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
}
