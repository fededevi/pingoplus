#pragma once

#include "vec.h"

template <class T, const u_int8_t size = 16> class Mat4
{
public:
    T e[size];

    constexpr Mat4() {};

    explicit inline constexpr Mat4(const T ( & init_array ) [size] )  {
        for (u_int8_t i = 0; i < size; i++)
            e[i] = init_array[i];
    };

public:
    const T & operator[]( std::size_t i ) const {
        return e[i];
    }

    static double fRand(double fMin, double fMax)
    {
        double f = (double)rand() / RAND_MAX;
        return fMin + f * (fMax - fMin);
    }

    static inline Mat4 random() { return  Mat4({
            fRand(-1,1),fRand(-1,1),fRand(-1,1),fRand(-1,1),
            fRand(-1,1),fRand(-1,1),fRand(-1,1),fRand(-1,1),
            fRand(-1,1),fRand(-1,1),fRand(-1,1),fRand(-1,1),
            fRand(-1,1),fRand(-1,1),fRand(-1,1),fRand(-1,1)
        });}

    static constexpr inline Mat4 identity() { return  Mat4({
            1, 0, 0, 0,
            0, 1, 0, 0,
            0, 0, 1, 0,
            0, 0, 0, 1
        });}

    static const inline Mat4 translation( const Vec3<T> & l ) {
        return {
            1,  0,  0, l.x,
            0,  1,  0, l.y,
            0,  0,  1, l.z,
            0,  0,  0,   1
        };
    }

    static const inline Mat4 rotation( const Vec3<T> & a, const T & phi ) {
        const T s = sin(phi);
        const T c = cos(phi);
        const T t = 1 - c;
        const T x = a.x;
        const T y = a.y;
        const T z = a.z;
        return (Mat4){{
            t*x*x + c, t*x*y - s*z, t*x*z + s*y, 0,
            t*x*y + s*z, t*y*y + c, t*y*z - s*x, 0,
            t*x*z - s*y, t*y*z + s*x, t*z*z + c, 0,
            0, 0, 0, 1
        }};
    }

    static const inline Mat4 rotationX( const T & phi ) {
        const T s = sin(phi);
        const T c = cos(phi);
        return (Mat4){{
            1,  0,  0, 0,
            0,  c, -s, 0,
            0,  s,  c, 0,
            0,  0,  0, 1
        }};
    }

    static const inline Mat4 rotationY( const T & phi ) {
        const T s = sin(phi);
        const T c = cos(phi);
        return (Mat4){{
            c,  0,  s, 0,
            0,  1,  0, 0,
            -s,  0,  c, 0,
            0,  0,  0, 1
        }};
    }

    static const inline Mat4 rotationZ( const T & phi ) {
        const T s = sin(phi);
        const T c = cos(phi);
        return (Mat4){{
            c, -s,  0, 0,
            s,  c,  0, 0,
            0,  0,  1, 0,
            0,  0,  0, 1
        }};
    }

    static const inline Mat4 scaling( const Vec3<T> & s ) {
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

    void scale( const Vec3<T> & s ) {
        *this = scaling(s) * *this;
    }
    void translate( const Vec3<T> & l ) {
        *this = translation(l) * *this;
    }
    void rotateX( const T & phi ) {
        *this = rotationX(phi) * *this;
    }
    void rotateY( const T & phi ) {
        *this = rotationY(phi) * *this;
    }
    void rotateZ( const T & phi ) {
        *this = rotationZ(phi) * *this;
    }
    void rotate( const Vec3<T> & axis, const T & phi ) {
        *this = rotation(axis,phi) * *this;
    }


    T determinant()
    {
        const auto & a = this->e;
        const T & a00 = a[0],  a01 = a[1],  a02 = a[2],  a03 = a[3];
        const T & a10 = a[4],  a11 = a[5],  a12 = a[6],  a13 = a[7];
        const T & a20 = a[8],  a21 = a[9],  a22 = a[10], a23 = a[11];
        const T & a30 = a[12], a31 = a[13], a32 = a[14], a33 = a[15];

        T b00 = a00 * a11 - a01 * a10;
        T b01 = a00 * a12 - a02 * a10;
        T b02 = a00 * a13 - a03 * a10;
        T b03 = a01 * a12 - a02 * a11;
        T b04 = a01 * a13 - a03 * a11;
        T b05 = a02 * a13 - a03 * a12;
        T b06 = a20 * a31 - a21 * a30;
        T b07 = a20 * a32 - a22 * a30;
        T b08 = a20 * a33 - a23 * a30;
        T b09 = a21 * a32 - a22 * a31;
        T b10 = a21 * a33 - a23 * a31;
        T b11 = a22 * a33 - a23 * a32;

        // Calculate the determinant
        return b00 * b11 - b01 * b10 + b02 * b09 + b03 * b08 - b04 * b07 + b05 * b06;
    }


    Mat4 inverse() const {
        Mat4 out;
        const auto & m = this->e;

        out.e[0] = m[5] * m[10] * m[15] - m[5] * m[11] * m[14] - m[9] * m[6] * m[15] + m[9] * m[7] * m[14] + m[13] * m[6] * m[11] - m[13] * m[7] * m[10];
        out.e[4] = -m[4] * m[10] * m[15] + m[4] * m[11] * m[14] + m[8] * m[6] * m[15] - m[8] * m[7] * m[14] - m[12] * m[6] * m[11] + m[12] * m[7] * m[10];
        out.e[8] = m[4] * m[9] * m[15] - m[4] * m[11] * m[13] - m[8] * m[5] * m[15] + m[8] * m[7] * m[13] + m[12] * m[5] * m[11] - m[12] * m[7] * m[9];
        out.e[12] = -m[4] * m[9] * m[14] + m[4] * m[10] * m[13] + m[8] * m[5] * m[14] - m[8] * m[6] * m[13] - m[12] * m[5] * m[10] + m[12] * m[6] * m[9];
        out.e[1] = -m[1] * m[10] * m[15] + m[1] * m[11] * m[14] + m[9] * m[2] * m[15] - m[9] * m[3] * m[14] - m[13] * m[2] * m[11] + m[13] * m[3] * m[10];
        out.e[5] = m[0] * m[10] * m[15] - m[0] * m[11] * m[14] - m[8] * m[2] * m[15] + m[8] * m[3] * m[14] + m[12] * m[2] * m[11] - m[12] * m[3] * m[10];
        out.e[9] = -m[0] * m[9] * m[15] + m[0] * m[11] * m[13] + m[8] * m[1] * m[15] - m[8] * m[3] * m[13] - m[12] * m[1] * m[11] + m[12] * m[3] * m[9];
        out.e[13] = m[0] * m[9] * m[14] - m[0] * m[10] * m[13] - m[8] * m[1] * m[14] + m[8] * m[2] * m[13] + m[12] * m[1] * m[10] - m[12] * m[2] * m[9];
        out.e[2] = m[1] * m[6] * m[15] - m[1] * m[7] * m[14] - m[5] * m[2] * m[15] + m[5] * m[3] * m[14] + m[13] * m[2] * m[7] - m[13] * m[3] * m[6];
        out.e[6] = -m[0] * m[6] * m[15] + m[0] * m[7] * m[14] + m[4] * m[2] * m[15] - m[4] * m[3] * m[14] - m[12] * m[2] * m[7] + m[12] * m[3] * m[6];
        out.e[10] = m[0] * m[5] * m[15] - m[0] * m[7] * m[13] - m[4] * m[1] * m[15] + m[4] * m[3] * m[13] + m[12] * m[1] * m[7] - m[12] * m[3] * m[5];
        out.e[14] = -m[0] * m[5] * m[14] + m[0] * m[6] * m[13] + m[4] * m[1] * m[14] - m[4] * m[2] * m[13] - m[12] * m[1] * m[6] + m[12] * m[2] * m[5];
        out.e[3] = -m[1] * m[6] * m[11] + m[1] * m[7] * m[10] + m[5] * m[2] * m[11] - m[5] * m[3] * m[10] - m[9] * m[2] * m[7] + m[9] * m[3] * m[6];
        out.e[7] = m[0] * m[6] * m[11] - m[0] * m[7] * m[10] - m[4] * m[2] * m[11] + m[4] * m[3] * m[10] + m[8] * m[2] * m[7] - m[8] * m[3] * m[6];
        out.e[11] = -m[0] * m[5] * m[11] + m[0] * m[7] * m[9] + m[4] * m[1] * m[11] - m[4] * m[3] * m[9] - m[8] * m[1] * m[7] + m[8] * m[3] * m[5];
        out.e[15] = m[0] * m[5] * m[10] - m[0] * m[6] * m[9] - m[4] * m[1] * m[10] + m[4] * m[2] * m[9] + m[8] * m[1] * m[6] - m[8] * m[2] * m[5];

        T det = m[0] * out[0] + m[1] * out[4] + m[2] * out[8] + m[3] * out[12];
        det = 1.0 / det;

        return out;

    }

};

template <class T> Mat4<T> operator*(const Mat4<T> & l, const Mat4<T> & r) {
    Mat4<T> out;
    out.e[0x0] = l[0x0] * r[0x0] + l[0x1] * r[0x4] + l[0x2] * r[0x8] + l[0x3] * r[0xc];
    out.e[0x1] = l[0x0] * r[0x1] + l[0x1] * r[0x5] + l[0x2] * r[0x9] + l[0x3] * r[0xd];
    out.e[0x2] = l[0x0] * r[0x2] + l[0x1] * r[0x6] + l[0x2] * r[0xa] + l[0x3] * r[0xe];
    out.e[0x3] = l[0x0] * r[0x3] + l[0x1] * r[0x7] + l[0x2] * r[0xb] + l[0x3] * r[0xf];
    out.e[0x4] = l[0x4] * r[0x0] + l[0x5] * r[0x4] + l[0x6] * r[0x8] + l[0x7] * r[0xc];
    out.e[0x5] = l[0x4] * r[0x1] + l[0x5] * r[0x5] + l[0x6] * r[0x9] + l[0x7] * r[0xd];
    out.e[0x6] = l[0x4] * r[0x2] + l[0x5] * r[0x6] + l[0x6] * r[0xa] + l[0x7] * r[0xe];
    out.e[0x7] = l[0x4] * r[0x3] + l[0x5] * r[0x7] + l[0x6] * r[0xb] + l[0x7] * r[0xf];
    out.e[0x8] = l[0x8] * r[0x0] + l[0x9] * r[0x4] + l[0xa] * r[0x8] + l[0xb] * r[0xc];
    out.e[0x9] = l[0x8] * r[0x1] + l[0x9] * r[0x5] + l[0xa] * r[0x9] + l[0xb] * r[0xd];
    out.e[0xA] = l[0x8] * r[0x2] + l[0x9] * r[0x6] + l[0xa] * r[0xa] + l[0xb] * r[0xe];
    out.e[0xB] = l[0x8] * r[0x3] + l[0x9] * r[0x7] + l[0xa] * r[0xb] + l[0xb] * r[0xf];
    out.e[0xC] = l[0xc] * r[0x0] + l[0xd] * r[0x4] + l[0xe] * r[0x8] + l[0xf] * r[0xc];
    out.e[0xD] = l[0xc] * r[0x1] + l[0xd] * r[0x5] + l[0xe] * r[0x9] + l[0xf] * r[0xd];
    out.e[0xE] = l[0xc] * r[0x2] + l[0xd] * r[0x6] + l[0xe] * r[0xa] + l[0xf] * r[0xe];
    out.e[0xF] = l[0xc] * r[0x3] + l[0xd] * r[0x7] + l[0xe] * r[0xb] + l[0xf] * r[0xf];
    return out;
};


using Mat4d = Mat4<double>;
using Mat4f = Mat4<float>;

