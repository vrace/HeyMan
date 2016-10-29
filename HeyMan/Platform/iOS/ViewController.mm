#import "ViewController.h"
#import "RenderLayerViewController.h"
#import <AVFoundation/AVCaptureDevice.h>
#import <AVFoundation/AVCaptureSession.h>
#import <AVFoundation/AVCaptureInput.h>
#import <AVFoundation/AVCaptureOutput.h>
#import <AVFoundation/AVMediaFormat.h>
#import <AVFoundation/AVCaptureVideoPreviewLayer.h>

#include "../../Camera/Camera.h"

struct CameraOutputBox
{
    CIImage *image;
};

namespace
{
    ViewController *_mainVC = nullptr;
}

@interface ViewController () <AVCaptureVideoDataOutputSampleBufferDelegate>
{
    CameraFeedHandler *cameraFeedHandler_;
}

@property (strong, nonatomic) RenderLayerViewController *renderLayerVC;

@property (strong, nonatomic) AVCaptureDevice *captureDevice;
@property (strong, nonatomic) AVCaptureSession *captureSession;
@property (strong, nonatomic) AVCaptureDeviceInput *captureInput;
@property (strong, nonatomic) AVCaptureVideoDataOutput *captureOutput;
@property (strong, nonatomic) AVCaptureVideoPreviewLayer *capturePreview;

@end

@implementation ViewController

- (void)viewDidLoad
{
    [super viewDidLoad];
    
    cameraFeedHandler_ = nullptr;
    _mainVC = self;
    
    [self setupCamera];
    _captureSession = self.captureSession;
    
    self.renderLayerVC = [self.storyboard instantiateViewControllerWithIdentifier:@"RenderLayer"];
    [self.view addSubview:self.renderLayerVC.view];
    [self addChildViewController:self.renderLayerVC];
    [self.renderLayerVC didMoveToParentViewController:self];
    
    self.renderLayerVC.view.frame = self.view.bounds;
}

- (void)viewDidDisappear:(BOOL)animated
{
    [super viewDidDisappear:animated];
    [self stopCameraCapture];
}

- (void)startCameraCapture:(CameraFeedHandler*)handler
{
    cameraFeedHandler_ = handler;
    [self.captureSession startRunning];
    self.capturePreview.frame = self.view.bounds;
}

- (void)stopCameraCapture
{
    [self.captureSession stopRunning];
}

- (void)setupCamera
{
    self.captureDevice = [AVCaptureDevice defaultDeviceWithMediaType:AVMediaTypeVideo];
    
    NSError *error = nil;
    self.captureInput = [AVCaptureDeviceInput deviceInputWithDevice:self.captureDevice error:&error];
    
    if (self.captureInput)
    {
        self.captureSession = [[AVCaptureSession alloc] init];
        [self.captureSession addInput:self.captureInput];
        
        self.capturePreview = [AVCaptureVideoPreviewLayer layerWithSession:self.captureSession];
        self.capturePreview.frame = self.view.bounds;
        
        [self.view.layer addSublayer:self.capturePreview];
        [self setupOutput];
    }
    else
    {
        NSLog(@"Can't open camera");
    }
}

- (void)setupOutput
{
    if (self.captureSession)
    {
        self.captureOutput = [[AVCaptureVideoDataOutput alloc] init];
        NSDictionary *settings = @{ (NSString*)kCVPixelBufferPixelFormatTypeKey: @(kCVPixelFormatType_32BGRA) };
        self.captureOutput.videoSettings = settings;
        self.captureOutput.alwaysDiscardsLateVideoFrames = YES;
        
        dispatch_queue_t outputQueue = dispatch_queue_create("CaptureOutputQueue", DISPATCH_QUEUE_SERIAL);
        [self.captureOutput setSampleBufferDelegate:self queue:outputQueue];
        
        if ([self.captureSession canAddOutput:self.captureOutput])
            [self.captureSession addOutput:self.captureOutput];
    }
}

- (void)captureOutput:(AVCaptureOutput *)captureOutput didOutputSampleBuffer:(CMSampleBufferRef)sampleBuffer fromConnection:(AVCaptureConnection *)connection
{
    /*
    CVImageBufferRef imageBuffer = CMSampleBufferGetImageBuffer(sampleBuffer);
    CVPixelBufferLockBaseAddress(imageBuffer, 0);
    
    void *baseAddress = CVPixelBufferGetBaseAddress(imageBuffer);
    
    size_t bytesPerRow = CVPixelBufferGetBytesPerRow(imageBuffer);
    size_t width = CVPixelBufferGetWidth(imageBuffer);
    size_t height = CVPixelBufferGetHeight(imageBuffer);
    
    if (cameraFeedHandler_)
        cameraFeedHandler_->CameraFeed(baseAddress, (int)bytesPerRow, (int)width, (int)height);
    
    CVPixelBufferUnlockBaseAddress(imageBuffer, 0);
    */
    
    CVImageBufferRef imageBuffer = CMSampleBufferGetImageBuffer(sampleBuffer);
    if (cameraFeedHandler_)
        cameraFeedHandler_->CameraFeed(imageBuffer);
}

bool CameraCaptureStart(CameraFeedHandler *cameraFeedHandler)
{
    if (_mainVC)
    {
        [_mainVC startCameraCapture:cameraFeedHandler];
        return true;
    }
    
    return false;
}

void CameraCaptureStop(void)
{
    if (_mainVC)
        [_mainVC stopCameraCapture];
}

@end
