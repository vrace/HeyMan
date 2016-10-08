#import "ViewController.h"
#import "RenderLayerViewController.h"

@interface ViewController ()

@property (strong, nonatomic) RenderLayerViewController *renderLayerVC;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    self.renderLayerVC = [self.storyboard instantiateViewControllerWithIdentifier:@"RenderLayer"];
    [self.view addSubview:self.renderLayerVC.view];
    [self addChildViewController:self.renderLayerVC];
    [self.renderLayerVC didMoveToParentViewController:self];
    
    self.renderLayerVC.view.frame = self.view.bounds;
}

@end
