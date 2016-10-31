#include "SceneImage.h"
#include "../../Application.h"
#include "../../Graphics/Graphics.h"

SceneImage::SceneImage(const std::string &id)
: SceneElement(id, SCENE_ELEMENT_IMAGE)
{
    
}

void SceneImage::SetTexture(const std::string &image)
{
    texture_ = LoadTexture(image);
    SetSize(vec2f(texture_->Width(), texture_->Height()));
}

void SceneImage::Render()
{
    float x = position_.x - size_.x * 0.5f;
    float y = position_.y - size_.y * 0.5f;
    
    texture_->Draw(*theGraphics, vec2((int)x, (int)y));
}
