#ifndef GEOMETRY_H
#define GEOMETRY_H

#include <cmath>

template <typename T>
struct Vec2
{
    T x;
    T y;

    Vec2() : x(0), y(0) {}
    Vec2(T x, T y) : x(x), y(y) {}

    inline Vec2 operator+(Vec2 v)
    {
        return Vec2(x + v.x, y + v.y);
    }

    inline Vec2 operator-(Vec2 v)
    {
        return Vec2(x - v.x, y - v.y);
    }

    inline Vec2 operator*(float val)
    {
        return Vec2(x * val, y * val);
    }
};


template <typename T>
struct Vec3
{
    T x;
    T y;
    T z;

    Vec3() : x(0), y(0) {}
    Vec3(T x, T y, T z) : x(x), y(y), z(z) {}

    inline Vec3 operator+(Vec3 v) const
    {
        return Vec3(x + v.x, y + v.y, z + v.z);
    }

    inline Vec3 operator-(Vec3 v) const
    {
        return Vec3(x - v.x, y - v.y, z - v.z);
    }

    inline Vec3 operator*(float val) const
    {
        return Vec3(x * val, y * val, z * val);
    }

    inline T operator*(Vec3 v) const
    {
        return x * v.x + y * v.y + z * v.z;
    }

    float norm() const
    {
        return sqrt(x * x + y * y + z * z);
    }

    Vec3 &normalize(T l = 1)
    {
        *this = *this * (l / norm());
        return *this;
    }
};

typedef Vec3<float> Vec3f;
typedef Vec2<float> Vec2f;

typedef Vec2<int> Vec2i;
typedef Vec3<int> Vec3i;

#endif // GEOMETRY_H
