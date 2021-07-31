/* UVA 10093 An Easy Problem */
/* 2021/5/2 Wendy */

#include <iostream>
#include <cstring>
using namespace std;

// Input
// Each line in the input file will contain an integer (as defined in mathematics) number of any integer
// base (2..62). You will have to determine what is the smallest possible base of that number for the given
// conditions. No invalid number will be given as input.
// Output
// If number with such condition is not possible output the line ‘such number is impossible!’ For each
// line of input there will be only a single line of output. The output will always be in decimal number
// system.
// Sample Input
// 3
// 5
// A
// Sample Output
// 4
// 6
// 11

/* input is a string
   imply that this might be a big number problem */

int isMultiple(string str, int base);

int main()
{
    string strR;
    string strBase = "0123456789" "ABCDEFGHIJKLMNOPQRSTUVWXYZ" "abcdefghijklmnopqrstuvwxyz";
    int strLen;
    int minBase = 2;
    // 10+26+26 = 62
    int N;

    // (0..9 and A..Z and a..z
    //     10   11  36    37  62

    while(cin >> strR) {
        strLen = strR.length();
        minBase = 2;

        for(int i = 0; i < strLen; i++) {
            strR[i] = strBase.find(strR[i]);
            if(strR[i] == -1) strR[i] = 0;
        }

        for(int i = 0; i < strLen; i++) {
            if(strR[i] + 1 > minBase) {
                minBase = strR[i] + 1;
            }
        }

        for(N = minBase; N <= 62; N++) {
            if(isMultiple(strR, N)) {
                break;
            }
        }

        if(N == 63) cout << "such number is impossible!" << endl;
        else cout << N << endl; 
    }
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