#ifndef HEYMAN_APPLICATION_H
#define HEYMAN_APPLICATION_H

#include "Scene/Scene.h"
#include <memory>

class Application
{
public:
	Application() = default;
	~Application() = default;

	bool Init();
	void Destroy();

	void Update(float delta);
	void Render();
    
    void ReplaceScene(std::unique_ptr<Scene> scene);

private:
	Application(const Application&) = delete;
	Application& operator= (const Application&) = delete;
    
private:
    std::unique_ptr<Scene> dyingScene_;
    std::unique_ptr<Scene> currentScene_;
};

#endif
