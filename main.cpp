#include <functional>
#include <iostream>
#include <sys/time.h>
#include <vector>

#include "math/matrix.h"
#include "math/printers.h"

#include "geometry/mesh.h"

#include "math/vector.h"

using namespace std;

int main()
{
    Vec4d vec = { 0, 0, 1, 1 };
   cout << vec << endl;

    Mat4d mat1 = Mat4d::translation(Vec3d{5,0,0});
    cout << mat1 << endl;

    Mat4d mat2 = Mat4d::rotationY(0.5);
    cout << mat2 << endl;

    Mat4d mat3 = mat1 * mat2;
    cout << mat3 << endl;

    vec = vec * mat3;
    cout << mat3 << endl;

    return 0;
}
