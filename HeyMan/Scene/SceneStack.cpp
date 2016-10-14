#include "SceneStack.h"
#include <algorithm>
#include <iterator>

SceneStackItem::SceneStackItem(Scene *scene, PushSceneMethod method)
    : scene_(scene)
    , method_(method)
{
}

Scene* SceneStackItem::GetScene() const
{
    return scene_;
}

PushSceneMethod SceneStackItem::GetMethod() const
{
    return method_;
}

SceneStack::SceneStack()
    : current_(nullptr)
{
}

bool SceneStack::PushScene(Scene *scene, PushSceneMethod method)
{
    auto it = std::find_if(begin(scenes_), end(scenes_), [scene] (const SceneStackItem &item) -> bool {
        return item.GetScene() == scene;
    });
    
    if (it == scenes_.end() && current_ != scene)
    {
        if (current_)
            current_->OnSuspend();
        
        scenes_.push_back(SceneStackItem(current_, method));
        
        current_ = scene;
        current_->OnEnter();
        
        return true;
    }
    
    return false;
}

void SceneStack::PopScene()
{
    if (current_)
        current_->OnExit();
    
    current_ = nullptr;
    
    if (!scenes_.empty())
    {
        current_ = scenes_.back().GetScene();
        current_->OnResume();
        
        scenes_.pop_back();
    }
}

void SceneStack::WalkStack(std::function<void (const SceneStackItem &)> func) const
{
    for (auto it = scenes_.rbegin(); it != scenes_.rend(); ++it)
        func(*it);
}

void SceneStack::Touch(int x, int y)
{
    if (current_)
        current_->OnTouch(x, y);
}

void SceneStack::Update(float delta)
{
    if (current_)
        current_->Update(delta);
    
    WalkStack([delta] (const SceneStackItem &item) {
        if ((item.GetMethod() & psmUpdate))
            item.GetScene()->Update(delta);
    });
}

void SceneStack::Render()
{
    if (current_)
        current_->Render();
    
    WalkStack([] (const SceneStackItem &item) {
        if ((item.GetMethod() & psmRender))
            item.GetScene()->Render();
    });
}
