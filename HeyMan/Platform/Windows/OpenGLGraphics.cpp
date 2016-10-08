#include "OpenGLGraphics.h"

OpenGLGraphics::OpenGLGraphics()
	: rc_(nullptr)
{
	vertices_.reserve(300);
}

void OpenGLGraphics::Clear()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	vertices_.clear();
}

void OpenGLGraphics::Triangle(const Vertex &a, const Vertex &b, const Vertex &c)
{
	// TODO: commit if texture changes

	vertices_.push_back(a);
	vertices_.push_back(b);
	vertices_.push_back(c);
}

void OpenGLGraphics::Commit()
{
	if (!vertices_.empty())
	{
		float *vp = (float*)&vertices_[0];

		unsigned parts = Vertex::vpVertex;
		for (const auto &v : vertices_)
			parts |= v.Parts();

		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, sizeof(Vertex), vp);

		if ((parts & Vertex::vpColor))
		{
			glEnableClientState(GL_COLOR_ARRAY);
			glColorPointer(4, GL_FLOAT, sizeof(Vertex), vp + 3);
		}

		if ((parts & Vertex::vpTexCoord))
		{
			glEnableClientState(GL_TEXTURE_COORD_ARRAY);
			glEnable(GL_TEXTURE);
			glBindTexture(GL_TEXTURE_2D, 0);  // TODO: get texture id
			glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex), vp + 7);
		}

		glDrawArrays(GL_TRIANGLES, 0, vertices_.size());

		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_COLOR_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);

		glDisable(GL_TEXTURE);

		vertices_.clear();
	}
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
	
	glEnable(GL_DEPTH_TEST);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

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
