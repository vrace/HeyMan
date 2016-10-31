#import "RenderLayerViewController.h"
#import "OpenGLESGraphics.h"
#import "../../Application.h"
#import <memory>

@interface RenderLayerViewController ()

@end

@implementation RenderLayerViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    OpenGLESGraphics::InitGraphics((GLKView*)self.view);
    
    Application *p = new Application();
    theApp = std::unique_ptr<Application>(p);
    theApp->Init();
}

- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    
    CGRect rc = self.view.frame;
    theApp->SetScreenSize(rc.size.width, rc.size.height);
}

- (void)update
{
    float delta = (float)self.timeSinceLastUpdate;
    theApp->Update(delta);
}

- (void)glkView:(GLKView*)view drawInRect:(CGRect)rect
{
    CGRect rc = self.view.frame;
    OpenGLESGraphics::BeginRender(&rc);
    theApp->Render();
    OpenGLESGraphics::EndRender();
}

- (void)touchesBegan:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    UITouch *touch = [[event allTouches] anyObject];
    CGPoint touchLocation = [touch locationInView:self.view];
    theApp->TouchBegin(vec2(touchLocation.x, touchLocation.y));
}

- (void)touchesMoved:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    UITouch *touch = [[event allTouches] anyObject];
    CGPoint touchLocation = [touch locationInView:self.view];
    theApp->TouchMove(vec2(touchLocation.x, touchLocation.y));
}

- (void)touchesEnded:(NSSet<UITouch *> *)touches withEvent:(UIEvent *)event
{
    UITouch *touch = [[event allTouches] anyObject];
    CGPoint touchLocation = [touch locationInView:self.view];
    theApp->TouchEnd(vec2(touchLocation.x, touchLocation.y));
}

@end
