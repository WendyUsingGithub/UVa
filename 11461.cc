/* UVa 11461 Square Numbers */
/* 2021/4/28 Wendy */

#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int bound = (int)sqrt(100000);
    int sqrNum[100001];
    int count;
    int a, b;

    memset(sqrNum, 0, 100001 * sizeof(int));
    for(int i = 0; i <= bound; i++) {
        sqrNum[i * i] = 1;
    }

    count = 0;
    for(int i = 0; i <= 100000; i++) {
        if(sqrNum[i] == 1) count++;
        sqrNum[i] = count;
    }

    while(1) {
        cin >> a >> b;
        if(a == 0 && b == 0) return 0;
        cout << sqrNum[b] - sqrNum[a - 1] << endl;
    }

    return 0;
}