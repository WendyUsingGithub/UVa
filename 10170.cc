/* UVA 10170 The Hotel with Infinite Rooms */
/* 2021/4/25 Wendy */

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int S;
    long long D;
    double L; /* leave day */

    while(cin >> S >> D) {
        /* (L+S) * (L-S+1) / 2 >= D */
        L =  2 * D + pow(S, 2) - S + (double)1 / 4;
        L = sqrt(L);
        L = L - (double)1 / 2;
        L = ceil(L);
        
        cout << (long long)L << endl;  
    }

    return 0;
}