#ifndef HEYMAN_CAMERA_H
#define HEYMAN_CAMERA_H

class CameraFeedHandler
{
public:
    virtual void CameraFeed() = 0;  // TOOD: what parameters do we need?
};

extern bool CameraCaptureStart(CameraFeedHandler *cameraFeedHandler);
extern void CameraCaptureStop(void);

#endif
