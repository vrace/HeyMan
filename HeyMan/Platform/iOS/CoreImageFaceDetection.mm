#import "Foundation/Foundation.h"
#import "CoreImageFaceDetection.h"
#import "CoreImage/CIImage.h"
#import "CoreImage/CIFeature.h"
#import "ImageIO/ImageIO.h"
#import "UIKit/UIKit.h"

CoreImageFaceDetection::CoreImageFaceDetection(CIDetector *detector)
: detector_(detector)
{
    
}

void CoreImageFaceDetection::CameraFeed(void *data)
{
    CVPixelBufferRef buf = (CVPixelBufferRef)data;
    CIImage *image = [CIImage imageWithCVPixelBuffer:buf];
    
    NSDictionary *options = @{
                             CIDetectorImageOrientation: [NSNumber numberWithInt:5]
    };
    
    NSArray *features = [detector_ featuresInImage:image options:options];
    
    DetectedFaceInfo info;
    info.imageBufferWidth = (int)CVPixelBufferGetWidth(buf);
    info.imageBufferHeight = (int)CVPixelBufferGetHeight(buf);
    
    Notify([](FaceDetectionDelegate *delegate) {
        delegate->FaceDetectionBegin();
    });
    
    for (NSUInteger i = 0; i < features.count; i++)
    {
        CIFaceFeature *feature = [features objectAtIndex:i];
        
        CGRect bounds = feature.bounds;
        info.faceOriginX = (int)bounds.origin.x;
        info.faceOriginY = (int)bounds.origin.y;
        info.faceWidth = (int)bounds.size.width;
        info.faceHeight = (int)bounds.size.height;
        
        Notify([this, &info](FaceDetectionDelegate *delegate) {
            delegate->FaceDetectionInfo(Transform(info));
        });
    }
    
    Notify([](FaceDetectionDelegate *delegate) {
        delegate->FaceDetectionEnd();
    });
}

DetectedFaceInfo CoreImageFaceDetection::Transform(const DetectedFaceInfo &info)
{
    DetectedFaceInfo face;
    
    face.imageBufferWidth = info.imageBufferHeight;
    face.imageBufferHeight = info.imageBufferWidth;
    face.faceOriginX = info.faceOriginY;
    face.faceOriginY = info.faceOriginX;
    face.faceWidth = info.faceHeight;
    face.faceHeight = info.faceWidth;
    
    return face;
}

std::unique_ptr<FaceDetection> InitFaceDetection(void)
{
    CIContext *context = [[CIContext alloc] init];
    
    NSDictionary *opts = @{
        CIDetectorAccuracy: CIDetectorAccuracyLow
    };
    
    CIDetector *detector = [CIDetector detectorOfType:CIDetectorTypeFace
                                              context:context
                                              options:opts];
    
    return std::unique_ptr<FaceDetection>(new CoreImageFaceDetection(detector));
}
