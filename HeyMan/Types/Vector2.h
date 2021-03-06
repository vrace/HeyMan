#ifndef HEYMAN_VECTOR2_H
#define HEYMAN_VECTOR2_H

template <class T>
struct Vector2
{
    Vector2(T _x = T(), T _y = T()) : x(_x), y(_y) {}
    T x, y;
};

using vec2 = Vector2<int>;
using vec2f = Vector2<float>;

#endif
