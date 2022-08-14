#include <ostream>

#include "mat4.h"

template <class T>
static  __attribute__ ((unused)) std::ostream& operator<<(std::ostream& os, const Mat4<T>& m) {
    os << "Mat4<" << typeid(T).name() << "> {\n";
    os << "\t" << m.e[ 0] << "\t" << m.e[ 1] << "\t" << m.e[ 2] << "\t" << m.e[ 3] << "\n";
    os << "\t" << m.e[ 4] << "\t" << m.e[ 5] << "\t" << m.e[ 6] << "\t" << m.e[ 7] << "\n";
    os << "\t" << m.e[ 8] << "\t" << m.e[ 9] << "\t" << m.e[10] << "\t" << m.e[11] << "\n";
    os << "\t" << m.e[12] << "\t" << m.e[13] << "\t" << m.e[14] << "\t" << m.e[15] << "\n}\n";
    return os;
}

#include "vec3.h"

template <class T>
static  __attribute__ ((unused)) std::ostream& operator<<(std::ostream& os, const Vec3<T>& m) {
    os << "Vec3<" << typeid(T).name() << "> {" << "\t" << m.e[ 0] << "\t" << m.e[ 1] << "\t" << m.e[ 2] << " }\n";
    return os;
}
