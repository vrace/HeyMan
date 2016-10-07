#include "OpenGLGraphics.h"

void OpenGLGraphics::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGLGraphics::Triangle()
{
	// TODO: draw triangle.
	// Need a vertex type
}

void OpenGLGraphics::Commit()
{
	// TODO: commit the draw
}

void OpenGLGraphics::Init(HDC hdc, RECT &rc)
{
	PIXELFORMATDESCRIPTOR desc = { 0 };
	desc.nSize = sizeof(desc);
	desc.cColorBits = 32;
	desc.cDepthBits = 16;
	desc.dwFlags = PFD_DRAW_TO_WINDOW | PFD_DOUBLEBUFFER | PFD_SUPPORT_OPENGL;
	desc.iPixelType = PFD_TYPE_RGBA;

	int pf = ChoosePixelFormat(hdc, &desc);
	SetPixelFormat(hdc, pf, &desc);

	rc_ = wglCreateContext(hdc);
	wglMakeCurrent(hdc, rc_);

	Resize(rc);

	glShadeModel(GL_SMOOTH);
	
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glClearColor(0x64 / 255.0f, 0x95 / 255.0f, 0xed / 255.0f, 1.0f);
}

void OpenGLGraphics::Destroy()
{
	wglDeleteContext(rc_);
}

void OpenGLGraphics::Resize(RECT &rc)
{
	int width = rc.right - rc.left;
	int height = rc.bottom - rc.top;

	glViewport(0, 0, width, height);
	
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, height, 0, -1, 1);
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void OpenGLGraphics::InitGraphics(HDC hdc, RECT &rc)
{
	theGraphics = std::make_unique<OpenGLGraphics>();
	
	OpenGLGraphics *g = dynamic_cast<OpenGLGraphics*>(theGraphics.get());
	g->Init(hdc, rc);
}

void OpenGLGraphics::DestroyGraphics()
{
	OpenGLGraphics *g = dynamic_cast<OpenGLGraphics*>(theGraphics.get());
	if (g)
		g->Destroy();

	theGraphics.reset();
}

void OpenGLGraphics::ResizeViewport(RECT &rc)
{
	OpenGLGraphics *g = dynamic_cast<OpenGLGraphics*>(theGraphics.get());
	if (g)
		g->Resize(rc);
}
