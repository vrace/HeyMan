#ifndef HEYMAN_CORE_IMAGE_FACE_DETECTION_H
#define HEYMAN_CORE_IMAGE_FACE_DETECTION_H

#import "../../FaceDetection/FaceDetection.h"
#import "CoreImage/CIDetector.h"

class CoreImageFaceDetection : public FaceDetection
{
public:
    CoreImageFaceDetection(CIDetector *detector);
    
    virtual void CameraFeed(void *) override;
    
private:
    DetectedFaceInfo Transform(const DetectedFaceInfo &info);
    
private:
    CIDetector *detector_;
};

#endif
