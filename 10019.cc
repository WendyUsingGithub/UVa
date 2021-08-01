/* UVa 10019 Funny Encryption Method */
/* 2021/8/1 Wendy */

#include <iostream>
using namespace std;

int dec2bin(int dec);
int hex2bin(int hex);

int main()
{
    int N = 0;
    int num = 0;
    int b1 = 0;
    int b2 = 0;

    cin >> N;

    for(int i = 0; i < N; i++) {
        cin >> num;
        b1 = dec2bin(num);
        b2 = hex2bin(num);
        cout << b1 << " " << b2 << endl;
    }

    return 0;
}

int dec2bin(int dec) 
{
    int tmp = 0;
    int count = 0;

    while(dec != 0) {
        tmp = dec % 2;
        if(tmp == 1) count++;
        dec = dec / 2;
    }

    return count;
}

int hex2bin(int hex)
{
    int count = 0;
    int tmp = 0;

    while(hex != 0) {
        tmp = hex % 10;
        hex = hex / 10;
        count = count + dec2bin(tmp); 
    }

    return count;
}