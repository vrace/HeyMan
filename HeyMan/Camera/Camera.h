#ifndef HEYMAN_CAMERA_H
#define HEYMAN_CAMERA_H

class CameraFeedHandler
{
public:
    virtual void CameraFeed(void *buffer, int bytesPerRow, int width, int height) = 0;
};

extern bool CameraCaptureStart(CameraFeedHandler *cameraFeedHandler);
extern void CameraCaptureStop(void);

#endif
