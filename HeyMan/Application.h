#ifndef HEYMAN_APPLICATION_H
#define HEYMAN_APPLICATION_H

#include "Graphics/Texture.h"

class Application
{
public:
	Application() = default;
	~Application() = default;

	bool Init();
	void Destroy();

	void Update(float delta);
	void Render();

private:
	Application(const Application&) = delete;
	Application& operator= (const Application&) = delete;
    
private:
    std::unique_ptr<Texture> bart_;
};

#endif
