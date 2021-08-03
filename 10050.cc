/* UVa 10050 Hartals */
/* 2021/8/2 Wendy */

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int T = 0;
    int N = 0;
    int n = 0;
    int P = 0;
    int h = 0;
    int pTable[100] = {0};
    int nTable[3651] = {0};
    int fri = 0;
    int sat = 0;
    int hartals = 0;

    cin >> T;
    for(int i = 0; i < T; i++) {
        hartals = 0;
        cin >> N;
        memset(nTable, 0, sizeof(int) * (N + 1));
        cin >> P;
        for(int j = 0; j < P; j++) {
            cin >> pTable[j];
        }
        
        for(int j = 0; j < P; j++) {
            h = pTable[j];
            n = N / h;
            for(int k = 1; k <= n; k++) {
                nTable[h * k] = 1;
            }
        }

        /* weekends */
        sat = fri = N / 7;
        if((N % 7) == 6) fri++;

        for(int j = 0; j < fri; j++) {
            nTable[7 * j + 6] = -1;
        }

        for(int j = 0; j < sat; j++) {
            nTable[7 * j + 7] = -1;
        }

        for(int j = 1; j <= N; j++) {
            if(nTable[j] == 1) hartals++;
        }

        cout << hartals << endl;
    }

    return 0;
}