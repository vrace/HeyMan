#ifndef HEYMAN_FACE_DETECTION_H
#define HEYMAN_FACE_DETECTION_H

#include "../Types/Subscribable.h"
#include "../Camera/Camera.h"
#include <functional>
#include <memory>

class FaceDetection
: public Subscribable<std::function<void (void)>>
, public CameraFeedHandler
{
public:
    using Subscribable = Subscribable<std::function<void (void)>>;
    
    FaceDetection() = default;
    virtual ~FaceDetection() = default;
};

std::unique_ptr<FaceDetection> InitFaceDetection(void);

#endif
