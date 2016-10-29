#ifndef HEYMAN_CAMERA_H
#define HEYMAN_CAMERA_H

class CameraFeedHandler
{
public:
    virtual void CameraFeed(void *image) = 0;
};

extern bool CameraCaptureStart(CameraFeedHandler *cameraFeedHandler);
extern void CameraCaptureStop(void);

#endif
