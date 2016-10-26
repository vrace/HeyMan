#include "ScanScene.h"
#include "../Camera/Camera.h"

void ScanScene::OnEnter()
{
    faceDetection_ = InitFaceDetection();
    CameraCaptureStart(&*faceDetection_);
    
    // TODO: subscribe to the detection result
}

void ScanScene::OnExit()
{
    CameraCaptureStop();
    faceDetection_.reset();
}
