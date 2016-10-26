#import "CoreImageFaceDetection.h"
#import "CoreImage/CIImage.h"
#import "CoreImage/CIFeature.h"
#import "ImageIO/ImageIO.h"
#import "UIKit/UIKit.h"

CoreImageFaceDetection::CoreImageFaceDetection(CIDetector *detector)
: detector_(detector)
{
    
}

void CoreImageFaceDetection::CameraFeed(void *buffer, int bytesPerRow, int width, int height)
{
    NSData *data = [NSData dataWithBytes:buffer length:bytesPerRow * height];
    CIImage *image = [CIImage imageWithBitmapData:data
                                      bytesPerRow:bytesPerRow
                                             size:CGSizeMake(width, height)
                                           format:kCIFormatRGBA8
                                       colorSpace:nil];
    
    
    
    NSDictionary *opts = @{
        CIDetectorImageOrientation: [[image properties] valueForKey:(__bridge NSString*)kCGImagePropertyOrientation]
    };
    
    NSArray *features = [detector_ featuresInImage:image options:opts];
    
    for (NSUInteger i = 0; i < features.count; i++)
    {
        CIFaceFeature *feature = [features objectAtIndex:i];
        NSLog(@"%@", NSStringFromCGRect(feature.bounds));
    }
}

std::unique_ptr<FaceDetection> InitFaceDetection(void)
{
    NSDictionary *opts = @{
        CIDetectorAccuracy: CIDetectorAccuracyLow
    };
    
    CIDetector *detector = [CIDetector detectorOfType:CIDetectorTypeFace
                                              context:nil
                                              options:opts];
    
    return std::unique_ptr<FaceDetection>(new CoreImageFaceDetection(detector));
}
