/* ★☆☆ UVa 10221 Satellites */
/* 2021/8/6 Wendy */

/* The distance will be a floating-point value with six digits after decimal point.*/

/* float and double are both floating point 
 * float  - single precision floating point 
 * double - double precision floating point */

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std; 

#define PI M_PI

int main()
{
    int s = 0;
    int a = 0;
    string str;
    int r = 6440;

    double radian = 0;

    while(cin >> s >> a >> str) {
        /* this explicit casting (double) is not neccessary to AC for unknown reason */
        if(str == "deg") radian = (double)a * PI / 180;

        /* this explicit casting (double) is critical to AC for unknown reason */
        if(str == "min") radian = (double)a / 60 * PI / 180;

        if(radian > PI) radian = 2 * PI - radian;
        cout << fixed << setprecision(6);
        cout << (s + r) * radian << " ";
        cout << 2 * (s + r) * sin(radian / 2) << endl;  
    }

    return 0;
}
