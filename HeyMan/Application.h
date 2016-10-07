#ifndef HEYMAN_APPLICATION_H
#define HEYMAN_APPLICATION_H

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
};

#endif
