#include <iostream>
#include <fstream>
#include "../Application.h"
#include "../Types/StringToken.h"
#include "ElementUIScene.h"
#include "UI/SceneCanvas.h"
#include "UI/SceneImage.h"

void ElementUIScene::LoadFromFile(const std::string &file)
{
    canvas_.reset();
    
    std::ifstream fs(ResourcePath(file));
    if (fs)
    {
        std::string line;
        SceneElement *current = nullptr;
        
        while (std::getline(fs, line))
        {
            if (!line.empty())
            {
                if (line.find("canvas:") == 0)
                {
                    auto size = theApp->ScreenSize();
                    sscanf(line.c_str() + strlen("canvas:"), "%d,%d", &size.x, &size.y);
                    
                    auto canvas = new SceneCanvas(size.x, size.y);
                    canvas_ = std::unique_ptr<SceneCanvas>(canvas);
                    
                    current = canvas;
                }
                else if (line.find("image:") == 0)
                {
                    StringToken token = TokenlizeString(line.substr(strlen("image:")), " :");
                    auto image = new SceneImage(token.head);
                    current = image;
                    if (canvas_)
                        canvas_->AddComponent(image);
                }
                else if (line.find("texture:") == 0)
                {
                    StringToken token = TokenlizeString(line.substr(strlen("texture:")), " :");
                    SceneElementTexturable *target = dynamic_cast<SceneElementTexturable*>(current);
                    if (target)
                        target->SetTexture(token.head);
                }
                else if (line.find("position:") == 0)
                {
                    vec2f pos;
                    sscanf(line.c_str() + strlen("position:"), "%f,%f", &pos.x, &pos.y);
                    if (current)
                        current->SetPosition(pos);
                }
                else if (line.find("size:") == 0)
                {
                    vec2f size;
                    sscanf(line.c_str() + strlen("size:"), "%f,%f", &size.x, &size.y);
                    if (current)
                        current->SetSize(size);
                }
            }
        }
    }
}

void ElementUIScene::Update(float delta)
{
    if (canvas_)
        canvas_->Update(delta);
}

void ElementUIScene::Render()
{
    if (canvas_)
        canvas_->Render();
}

void ElementUIScene::OnTouchEnd(const vec2 &pt)
{
    if (canvas_)
    {
        auto target = canvas_->CanvasHitTest(vec2f(pt.x, pt.y));
        if (target)
            OnTouchElement(*target);
    }
}

void ElementUIScene::OnTouchElement(SceneElement &element)
{
    std::cout << "Touch Element " << element.ID() << std::endl;
}
