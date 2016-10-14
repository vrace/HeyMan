#ifndef HEYMAN_VECTOR3_H
#define HEYMAN_VECTOR3_H

template <class T>
struct Vector3
{
    Vector3(T _x = T(), T _y = T(), T _z = T()) : x(_x), y(_y), z(_z) {}
    T x, y, z;
};

using vec3 = Vector3<int>;
using vec3f = Vector3<float>;

#endif
