#include "SceneCanvas.h"
#include "../../Application.h"
#include "../../Graphics/Graphics.h"
#include <algorithm>

SceneCanvas::SceneCanvas(int width, int height)
: SceneElement("__root_canvas__", SCENE_ELEMENT_CANVAS)
{
    SetSize(vec2f(width, height));
    
    vec2 size = theApp->ScreenSize();
    SetPosition(vec2f((size.x - width) * 0.5f, (size.y - height) * 0.5f));
}

SceneCanvas::~SceneCanvas()
{
    for (auto p : components_)
        delete p;
}

void SceneCanvas::AddComponent(SceneElement *component)
{
    if (std::find(std::begin(components_), std::end(components_), component) == components_.end())
        components_.push_back(component);
}

void SceneCanvas::Update(float delta)
{
    for (auto p : components_)
        p->Update(delta);
}

void SceneCanvas::Render()
{
    for (auto p : components_)
        p->Render();
}

SceneElement* SceneCanvas::CanvasHitTest(const vec2f &pt)
{
    for (auto it = components_.rbegin(); it != components_.rend(); ++it)
    {
        if ((*it)->HitTest(pt))
            return *it;
    }
    
    return nullptr;
}
