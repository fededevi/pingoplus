#include <functional>
#include <iostream>
#include <sys/time.h>

#include "math/mat4.h"
#include "math/printers.h"

using namespace std;


int main()
{
    Mat4d mat = Mat4d::random();

    //benchamerk inverse    
    struct timeval start, end;
    gettimeofday(&start, NULL);
    for (int i = 0; i < 100000000; i++)
    {
        mat = mat.inverse();
    }
    gettimeofday(&end, NULL);

    //print 
    cout << "inverse: " << endl;
    cout << mat << endl;
    cout << "time: " << endl;
    cout << (end.tv_sec - start.tv_sec) * 1000 + (end.tv_usec - start.tv_usec) / 1000 << "ms" << endl;

    return 0;
}
