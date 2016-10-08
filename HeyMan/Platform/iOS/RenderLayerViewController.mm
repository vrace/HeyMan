#import "RenderLayerViewController.h"
#import "OpenGLESGraphics.h"

@interface RenderLayerViewController ()

@end

@implementation RenderLayerViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    OpenGLESGraphics::InitGraphics((GLKView*)self.view);
}

- (void)update
{
    //float delta = (float)self.timeSinceLastUpdate;
}

- (void)glkView:(GLKView*)view drawInRect:(CGRect)rect
{
    CGRect rc = self.view.frame;
    OpenGLESGraphics::BeginRender(&rc);
    
    theGraphics->Triangle(
        Vertex(100, 100, 0, 1, 0, 0, 1),
        Vertex(100, 200, 0, 0, 1, 0, 1),
        Vertex(200, 200, 0, 0, 0, 1, 1));
    
    OpenGLESGraphics::EndRender();
}

@end
