#pragma once

#include <cmath>

template <class T> class Vec3
{
public:
    T e[3];

private:
    Vec3() = delete;

public:
    const T & operator[](std::size_t i) const {
        return e[i];
    }

    T dot( const Vec3 & v ) const {
        return e[0] * v[0] + e[1] * v[1] + e[2] * v[2];
    }


    Vec3 cross( const Vec3 & v ) const {
        return {
                e[1] * v[2] - e[2] * v[1],
                e[2] * v[0] - e[0] * v[2],
                e[0] * v[1] - e[1] * v[0]
        };
    }

    Vec3 normalized() const {
        T s = sqrt( e[0]*e[0] + e[1]*e[1] + e[2]*e[2] );
        return { e[0] / s, e[1] / s, e[2] / s };
    }

    void normalize() {
        T s = sqrt( e[0]*e[0] + e[1]*e[1] + e[2]*e[2] );
        e[0] = e[0]/s;
        e[1] = e[1]/s;
        e[2] = e[2]/s;
    }

};


template <class T> Vec3<T> operator+(const Vec3<T> & l, const Vec3<T> & r) {
    return {l[0] + r[0], l[0] + r[0], l[0] + r[0]};
};

template <class T> Vec3<T> operator-(const Vec3<T> & l, const Vec3<T> & r) {
    return {l[0] - r[0], l[0] - r[0], l[0] - r[0]};
};

template <class T> Vec3<T> operator/(const Vec3<T> & l, const Vec3<T> & r) {
    return {l[0] / r[0], l[0] / r[0], l[0] / r[0]};
};

using Vec3d = Vec3<double>;
using Vec3f = Vec3<float>;

