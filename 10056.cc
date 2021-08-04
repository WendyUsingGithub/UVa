/* ★☆☆ UVa 10056 What is the Probability? */
/* 2021/4/24 Wendy */

#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main()
{
    int C, N, I;
    float P;
    double pb;

    cin >> C;
    for(int i = 0; i < C; i++) {
        cin >> N >> P >> I;
        if(P == 0) cout << "0.0000" << endl;
        else{
            /* probability = P * (1-P)^(I-1) * (1 / (1 - (1-P)^N)) */
            pb = P * pow(1-P, I-1) / (1 - pow(1-P, N)); 
            cout << fixed << setprecision(4) << pb << endl;
        }
    }

    return 0;
}