#ifndef HEYMAN_FACE_DETECTION_H
#define HEYMAN_FACE_DETECTION_H

#include "../Types/Subscribable.h"
#include "../Camera/Camera.h"
#include <functional>
#include <memory>

struct DetectedFaceInfo
{
    int imageBufferWidth;
    int imageBufferHeight;
    int faceOriginX;
    int faceOriginY;
    int faceWidth;
    int faceHeight;
};

class FaceDetectionDelegate
{
public:
    virtual void FaceDetectionBegin() = 0;
    virtual void FaceDetectionEnd() = 0;
    virtual void FaceDetectionInfo(const DetectedFaceInfo &info) = 0;
};

class FaceDetection
: public Subscribable<FaceDetectionDelegate*>
, public CameraFeedHandler
{
public:
    FaceDetection() = default;
    virtual ~FaceDetection() = default;
};

std::unique_ptr<FaceDetection> InitFaceDetection(void);

#endif
