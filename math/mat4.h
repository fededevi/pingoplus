#pragma once

#include "vec.h"

template <class T> class Mat4
{
public:
    T e[16];

private:
    Mat4() = delete;

public:
    const T & operator[](std::size_t i) const {
        return e[i];
    }

    static const inline Mat4 identity() { return {
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        };}

    static const inline Mat4 translation(const Vec3<T> & l) {
        return {
            1,  0,  0, l.x,
            0,  1,  0, l.y,
            0,  0,  1, l.z,
            0,  0,  0,   1
        };
    }

    static const inline Mat4 rotationX(T phi) {
        const T s = sin(phi);
        const T c = cos(phi);
        return (Mat4){{
            1,  0,  0, 0,
            0,  c, -s, 0,
            0,  s,  c, 0,
            0,  0,  0, 1
        }};
    }

    static const inline Mat4 rotationY(T phi) {
        const T s = sin(phi);
        const T c = cos(phi);
        return (Mat4){{
            c,  0,  s, 0,
            0,  1,  0, 0,
            -s,  0,  c, 0,
            0,  0,  0, 1
        }};
    }

    static const inline Mat4 rotationZ(T phi) {
        const T s = sin(phi);
        const T c = cos(phi);
        return (Mat4){{
            c, -s,  0, 0,
            s,  c,  0, 0,
            0,  0,  1, 0,
            0,  0,  0, 1
        }};
    }

    static const inline Mat4 scaling(Vec3<T> s) {
        const T p = s.x;
        const T q = s.y;
        const T r = s.z;
        return (Mat4){{
            p,  0,  0, 0,
            0,  q,  0, 0,
            0,  0,  r, 0,
            0,  0,  0, 1
        }};
    }

};


using Mat4d = Mat4<double>;
using Mat4f = Mat4<float>;

