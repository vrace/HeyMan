#ifndef HEYMAN_APPLICATION_H
#define HEYMAN_APPLICATION_H

#include "Scene/SceneStack.h"
#include <memory>

enum ApplicationScenes
{
    asWelcome,
    asRecord,
    asScan,
    asBart,
    
    asNumScenes,
};

class Application : public SceneStack
{
public:
	Application() = default;
	~Application() = default;

	bool Init();
	void Destroy();
    
    void PushScene(ApplicationScenes scene, PushSceneMethod method = psmSuspend);

private:
	Application(const Application&) = delete;
	Application& operator= (const Application&) = delete;
    
private:
    std::unique_ptr<Scene> sceneStorage_[asNumScenes];
};

#endif
