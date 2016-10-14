#include <iostream>
#include "Application.h"
#include "Graphics/Graphics.h"
#include "Scene/GhostBartScene.h"

bool Application::Init()
{
	std::cout << "**** APPLICATION INIT ****" << std::endl;
    
    sceneStorage_[asBart] = std::unique_ptr<Scene>(new GhostBartScene());
    
    PushScene(asBart);
    
	return true;
}

void Application::Destroy()
{
	std::cout << "**** APPLICATION DESTROY ****" << std::endl;
}

void Application::PushScene(ApplicationScenes scene, PushSceneMethod method)
{
    SceneStack::PushScene(sceneStorage_[scene].get(), method);
}
