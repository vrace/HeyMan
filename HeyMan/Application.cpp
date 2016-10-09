#include <iostream>
#include "Application.h"
#include "Graphics/Graphics.h"
#include "Scene/GhostBartScene.h"

bool Application::Init()
{
	std::cout << "**** APPLICATION INIT ****" << std::endl;
    
    ReplaceScene(std::unique_ptr<Scene>(new GhostBartScene()));
    
	return true;
}

void Application::Destroy()
{
	std::cout << "**** APPLICATION DESTROY ****" << std::endl;
    
    if (dyingScene_)
        dyingScene_->SceneExit();
    
    if (currentScene_)
        currentScene_->SceneExit();
}

void Application::Update(float delta)
{
    if (currentScene_)
        currentScene_->Update(delta);
    
    if (dyingScene_)
    {
        dyingScene_->SceneExit();
        dyingScene_.reset();
    }
}

void Application::Render()
{
    if (dyingScene_)
        dyingScene_->Render();
    
    if (currentScene_)
        currentScene_->Render();
}

void Application::ReplaceScene(std::unique_ptr<Scene> scene)
{
    if (dyingScene_)
        dyingScene_->SceneExit();
    
    if (currentScene_)
        dyingScene_ = std::move(currentScene_);
    
    currentScene_ = std::move(scene);
    currentScene_->SceneEnter();
}
