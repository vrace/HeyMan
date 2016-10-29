#include "ScanScene.h"
#include "../Camera/Camera.h"
#include "../Graphics/Graphics.h"
#include "../Application.h"
#include <iostream>

void ScanScene::OnEnter()
{
    bart_ = LoadTexture("bart.jpg");
    
    faceDetection_ = InitFaceDetection();
    CameraCaptureStart(&*faceDetection_);
    
    faceDetection_->Subscribe(this);
}

void ScanScene::OnExit()
{
    CameraCaptureStop();
    faceDetection_.reset();
}

void ScanScene::Render()
{
    Graphics &g = *theGraphics;
    
    vec2 screen = theApp->ScreenSize();
    
    for (const auto &face : faces_)
    {
        float xs = (float)screen.x / face.imageBufferWidth;
        float ys = (float)screen.y / face.imageBufferHeight;
        
        bart_->Draw(g,
                    vec2(face.faceOriginX * xs, face.faceOriginY * ys),
                    vec2(face.faceWidth * xs, face.faceHeight * ys));
    }
}

void ScanScene::FaceDetectionBegin()
{
    faces_.clear();
}

void ScanScene::FaceDetectionEnd()
{
    
}

void ScanScene::FaceDetectionInfo(const DetectedFaceInfo &info)
{
    faces_.push_back(info);
}
