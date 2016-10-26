#ifndef HEYMAN_SCAN_SCENE_H
#define HEYMAN_SCAN_SCENE_H

#include "Scene.h"
#include "../FaceDetection/FaceDetection.h"

class ScanScene : public Scene
{
public:
    virtual void OnEnter() override;
    virtual void OnExit() override;
    
private:
    std::unique_ptr<FaceDetection> faceDetection_;
};

#endif
