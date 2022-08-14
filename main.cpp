#include <iostream>

#include "math/mat4.h"
#include "math/mathprinters.h"

using namespace std;

int main()
{
    Mat4d mat = Mat4d::identity();
    cout << mat << endl;

    Vec3d vec = {.25443,5,3};
    vec = vec.normalized();
    cout << vec << vec.normalized() << endl;
    return 0;
}
