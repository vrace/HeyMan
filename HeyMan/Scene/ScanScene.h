#ifndef HEYMAN_SCAN_SCENE_H
#define HEYMAN_SCAN_SCENE_H

#include "Scene.h"
#include "../Graphics/Texture.h"
#include "../FaceDetection/FaceDetection.h"

class ScanScene
: public Scene
, public FaceDetectionDelegate
{
public:
    virtual void OnEnter() override;
    virtual void OnExit() override;
    
    virtual void Render() override;
    
    virtual void FaceDetectionBegin() override;
    virtual void FaceDetectionEnd() override;
    virtual void FaceDetectionInfo(const DetectedFaceInfo &info) override;
    
private:
    std::unique_ptr<FaceDetection> faceDetection_;
    std::unique_ptr<Texture> bart_;
    std::unique_ptr<Texture> name_;
    std::vector<DetectedFaceInfo> faces_;
};

#endif
