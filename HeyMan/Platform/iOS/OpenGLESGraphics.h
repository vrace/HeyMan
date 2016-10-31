#import "../../Graphics/Graphics.h"
#import "OpenGLESTexture.h"
#import <GLKit/GLKit.h>

class OpenGLESGraphics : public Graphics
{
public:
    OpenGLESGraphics();
    ~OpenGLESGraphics() = default;
    
    virtual void Clear() override;
    virtual void SetTexture(const Texture *texture) override;
    virtual void Triangle(const Vertex &a, const Vertex &b, const Vertex &c) override;
    virtual void Commit() override;
    
    virtual void DrawBlock(std::function<void (Graphics &g)> drawFunc) override;
    
    static void InitGraphics(GLKView *view);
    static void BeginRender(CGRect *rect);
    static void EndRender();
    
private:
    OpenGLESGraphics(const OpenGLESGraphics&) = delete;
    OpenGLESGraphics& operator= (const OpenGLESGraphics&) = delete;
    
    void Init(GLKView *view);
    
private:
    EAGLContext *context_;
    const OpenGLESTexture *texture_;
};
