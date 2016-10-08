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
    OpenGLESGraphics::EndRender();
}

@end
