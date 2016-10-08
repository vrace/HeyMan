#import "OpenGLESGraphics.h"
#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>

void OpenGLESGraphics::Clear()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void OpenGLESGraphics::Triangle(const Vertex &a, const Vertex &b, const Vertex &c)
{
    // No optimization yet
    unsigned parts = a.Parts() | b.Parts() | c.Parts();
    Vertex arr[] = { a, b, c };
    float *vp = (float*)&arr[0];
    
    glEnableClientState(GL_VERTEX_ARRAY);
    
    if ((parts & Vertex::vpColor))
        glEnableClientState(GL_COLOR_ARRAY);
    
    if ((parts & Vertex::vpTexCoord))
    {
        glEnable(GL_TEXTURE);
        glBindTexture(GL_TEXTURE_2D, 0); // huh?
        glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    }
    
    glVertexPointer(3, GL_FLOAT, sizeof(Vertex), vp);
    glColorPointer(4, GL_FLOAT, sizeof(Vertex), vp + 3);
    glTexCoordPointer(2, GL_FLOAT, sizeof(Vertex), vp + 7);
    
    glDrawArrays(GL_TRIANGLES, 0, 3);
    
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
    
    glDisable(GL_TEXTURE);
    glDisableClientState(GL_TEXTURE_COORD_ARRAY);
}

void OpenGLESGraphics::Commit()
{
    // TODO:
}

void OpenGLESGraphics::Init(GLKView *view)
{
    context_ = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES1];
    
    view.context = context_;
    view.drawableDepthFormat = GLKViewDrawableDepthFormat24;
    view.opaque = NO;
    view.layer.opaque = NO;
    view.alpha = 1;
    view.backgroundColor = [UIColor clearColor];
    
    [EAGLContext setCurrentContext:context_];
    
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glShadeModel(GL_SMOOTH);
}

void OpenGLESGraphics::InitGraphics(GLKView *view)
{
    // Looks like make_unique doesn't work for xcode
    OpenGLESGraphics *g = new OpenGLESGraphics();
    theGraphics = std::unique_ptr<Graphics>(g);
    g->Init(view);
}

void OpenGLESGraphics::BeginRender(CGRect *rect)
{
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrthof(0, rect->size.width, rect->size.height, 0, -1, 1);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void OpenGLESGraphics::EndRender()
{
    OpenGLESGraphics *g = dynamic_cast<OpenGLESGraphics*>(theGraphics.get());
    if (g)
        g->Commit();
}
