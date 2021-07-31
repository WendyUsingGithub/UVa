/* UVa 10093 An Easy Problem */
/* 2021/7/31 Wendy */

#include <iostream>
#include <cstring>
using namespace std;

int isMultiple(string str, int base);

/* this is a big number problem */
/* testcase includes negative input */

int main()
{
    string strR;
    string strBase = "0123456789" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz";
    int strLen;
    int minBase = 2;
    int N;

    while(cin >> strR) {
        strLen = strR.length();
        minBase = 2;

        for(int i = 0; i < strLen; i++) {
            strR[i] = strBase.find(strR[i]);
            if(strR[i] == -1) strR[i] = 0; /* for negative input */
        }

        for(int i = 0; i < strLen; i++) {
            if(strR[i] + 1 > minBase) {
                minBase = strR[i] + 1;
            }
        }

        for(N = minBase; N <= 62; N++) {
            if(isMultiple(strR, N)) { /* strR is a N base big number */
                break;
            }
        }

        if(N == 63) cout << "such number is impossible!" << endl;
        else cout << N << endl; 
    }

    return 0;
}

int isMultiple(string str, int N) 
{
    int strLen = str.length();
    int tmp = 0;

    for(int i = 0; i < strLen; i++) {
        tmp = tmp * N + str[strLen - 1 - i];
        tmp = tmp % (N - 1);
    }

    if(tmp == 0) return 1;
    else return 0;
}