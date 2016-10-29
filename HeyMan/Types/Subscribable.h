#ifndef HEYMAN_SUBSCRIBABLE_H
#define HEYMAN_SUBSCRIBABLE_H

#include <vector>
#include <algorithm>
#include <functional>

template <class SUBSCRIBER>
class Subscribable
{
public:
    using SubscriberType = SUBSCRIBER;
    
    Subscribable() = default;
    virtual ~Subscribable() = default;
    
    void Subscribe(SUBSCRIBER s)
    {
        auto it = std::find(std::begin(subscribers_), std::end(subscribers_), s);
        if (it == subscribers_.end())
            subscribers_.push_back(s);
    }
    
    void Unsubscribe(SUBSCRIBER s)
    {
        auto it = std::find(std::begin(subscribers_), std::end(subscribers_), s);
        if (it != subscribers_.end())
            subscribers_.erase(it);
    }
    
    void Notify(std::function<void (SUBSCRIBER&)> func)
    {
        std::for_each(subscribers_.begin(), subscribers_.end(), func);
    }
    
private:
    std::vector<SUBSCRIBER> subscribers_;
};

#endif
