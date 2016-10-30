#include "ScanScene.h"
#include "../Camera/Camera.h"
#include "../Graphics/Graphics.h"
#include "../Application.h"
#include <iostream>

void ScanScene::OnEnter()
{
    bart_ = LoadTexture("bart.jpg");
    name_ = LoadTexture("name.png");
    
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
    auto faces = faces_;
    
    Graphics &g = *theGraphics;
    
    vec2 screen = theApp->ScreenSize();
    
    for (const auto &face : faces)
    {
        float xs = (float)screen.x / face.imageBufferWidth;
        float ys = (float)screen.y / face.imageBufferHeight;
        
        bart_->Draw(g,
                    vec2(face.faceOriginX * xs, face.faceOriginY * ys),
                    vec2(face.faceWidth * xs, face.faceHeight * ys));
        
        int x = face.faceOriginX * xs + (face.faceWidth * xs - name_->Width()) / 2;
        int y = face.faceOriginY * xs - name_->Height();
        
        name_->Draw(g, vec2(x, y));
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
