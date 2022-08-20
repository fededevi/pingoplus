#pragma once

#include <cmath>

template <class T> class Vec4
{
public:
    T e[4];
    T x() const {return e[0];}
    T y() const {return e[1];}
    T z() const {return e[2];}
    T w() const {return e[3];}

private:
    Vec4() = delete;

public:
    const T & operator[](std::size_t i) const {
        return e[i];
    }

    T dot( const Vec4 & v ) const {
        return e[0] * v[0] + e[1] * v[1] + e[2] * v[2] + e[3] * v[3];
    }

    Vec4 normalized() const {
        T s = sqrt( e[0]*e[0] + e[1]*e[1] + e[2]*e[2] + e[3]*e[3] );
        return { e[0] / s, e[1] / s, e[2] / s, e[3] / s };
    }

    void normalize() {
        T s = sqrt( e[0]*e[0] + e[1]*e[1] + e[2]*e[2] + e[3]*e[3] );
        e[0] = e[0]/s;
        e[1] = e[1]/s;
        e[2] = e[2]/s;
        e[3] = e[3]/s;
    }

};

template <class T> Vec4<T> operator+(const Vec4<T> & l, const Vec4<T> & r) {
    return {l[0] + r[0], l[1] + r[1], l[2] + r[2], l[3] + r[3] };
};

template <class T> Vec4<T> operator-(const Vec4<T> & l, const Vec4<T> & r) {
    return {l[0] - r[0], l[1] - r[1], l[2] - r[2], l[3] - r[3] };
};

template <class T> Vec4<T> operator/(const Vec4<T> & l, const Vec4<T> & r) {
    return {l[0] / r[0], l[1] / r[1], l[2] / r[2], l[3] / r[3],};
};

template <class T> class Vec3
{
public:
    T e[3];
    T x() const {return e[0];}
    T y() const {return e[1];}
    T z() const {return e[2];}

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
    return {l[0] + r[0], l[1] + r[1], l[2] + r[2]};
};

template <class T> Vec3<T> operator-(const Vec3<T> & l, const Vec3<T> & r) {
    return {l[0] - r[0], l[1] - r[1], l[2] - r[2]};
};

template <class T> Vec3<T> operator/(const Vec3<T> & l, const Vec3<T> & r) {
    return {l[0] / r[0], l[1] / r[1], l[2] / r[2]};
};

template <class T> class Vec2
{
public:
    T e[2];
    T x() const {return e[0];}
    T y() const {return e[1];}

private:
    Vec2() = delete;

public:
    const T & operator[](std::size_t i) const {
        return e[i];
    }

    T dot( const Vec2 & v ) const {
        return e[0] * v[0] + e[1] * v[1];
    }

    Vec2 normalized() const {
        T s = sqrt( e[0]*e[0] + e[1]*e[1] );
        return { e[0] / s, e[1] / s };
    }

    void normalize() {
        T s = sqrt( e[0]*e[0] + e[1]*e[1] + e[2]*e[2] );
        e[0] = e[0]/s;
        e[1] = e[1]/s;
        e[2] = e[2]/s;
    }

};


template <class T> Vec2<T> operator+(const Vec2<T> & l, const Vec2<T> & r) {
    return { l[0] + r[0], l[1] + r[1] };
};

template <class T> Vec2<T> operator-(const Vec2<T> & l, const Vec2<T> & r) {
    return { l[0] - r[0], l[1] - r[1] };
};

template <class T> Vec2<T> operator/(const Vec2<T> & l, const Vec2<T> & r) {
    return { l[0] / r[0], l[1] / r[1] };
};

using Vec4d = Vec4<double>;
using Vec4f = Vec4<float>;

using Vec3d = Vec3<double>;
using Vec3f = Vec3<float>;

using Vec2d = Vec2<double>;
using Vec2f = Vec2<float>;
