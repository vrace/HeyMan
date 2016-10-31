#include "SceneElement.h"
#include "../../Application.h"
#include <stdlib.h>
#include <math.h>
#include <iostream>

SceneElement::SceneElement(const std::string &id, int type)
: id_(id)
, type_(type)
{
    
}

void SceneElement::Update(float delta)
{
    
}

void SceneElement::Render()
{
    
}

const std::string& SceneElement::ID() const
{
    return id_;
}

void SceneElement::SetPosition(const vec2f &pos)
{
    position_ = pos;
}

void SceneElement::SetSize(const vec2f &size)
{
    size_ = size;
}

bool SceneElement::HitTest(const vec2f &pt)
{
    float dx = fabs(pt.x - position_.x);
    float dy = fabs(pt.y - position_.y);
    
    return dx <= size_.x * 0.5f && dy <= size_.y * 0.5f;
}
