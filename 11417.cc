/* ★☆☆ UVa 11417 GCD */
/* 2021/8/4 Wendy */

#include <iostream>
using namespace std; 

int GCD(int i,int j);

int main()
{
    int N = 0;
    int G = 0;

    while(1)
    {
        cin >> N;
        if(N == 0) break;

        G = 0;
        for(int i = 1; i < N; i++) {
            for(int j = i + 1; j <= N; j++) {
                G = G + GCD(i,j);
            }
        }
        cout << G << endl;
    }

    return 0;
}

int GCD(int i,int j)
{
    int nBig = (i > j) ? i : j;
    int nSmall = (i < j) ? i : j;
    int tmp = 0;

    while(nSmall > 0) {
        tmp = nSmall;
        nSmall = nBig % nSmall;
        nBig = tmp;
    }

    return nBig;
}