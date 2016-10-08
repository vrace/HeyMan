#import "RenderLayerViewController.h"
#import <OpenGLES/ES1/gl.h>
#import <OpenGLES/ES1/glext.h>

@interface RenderLayerViewController ()

@property (strong, nonatomic) EAGLContext *context;

@end

@implementation RenderLayerViewController

- (void)viewDidLoad
{
    [super viewDidLoad];

    self.context = [[EAGLContext alloc] initWithAPI:kEAGLRenderingAPIOpenGLES1];

    GLKView *view = (GLKView*)self.view;
    view.context = self.context;
    view.drawableDepthFormat = GLKViewDrawableDepthFormat24;
    view.opaque = NO;
    view.layer.opaque = NO;
    view.alpha = 1;
    view.backgroundColor = [UIColor clearColor];

    [EAGLContext setCurrentContext:self.context];

    glEnable(GL_DEPTH_TEST);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
    glShadeModel(GL_SMOOTH);
}

- (void)update
{
    float delta = (float)self.timeSinceLastUpdate;
}

- (void)glkView:(GLKView*)view drawInRect:(CGRect)rect
{
    glClearColor(0x64 / 255.0f, 0x95 / 255.0f, 0xed / 255.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

@end
