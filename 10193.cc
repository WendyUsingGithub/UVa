/* UVa 10193 All You Need Is Love */
/* 2021/8/4 Wendy */

#include <iostream>
#include <cstring>
#include <math.h>
using namespace std;

int bin2dec(string str);
int gcd(int n1, int n2);

int main()
{
    int T = 0;
    string s1;
    string s2;
    int n1 = 0;
    int n2 = 0;
    int love = 0;

    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> s1;
        cin >> s2;
        n1 = bin2dec(s1);
        n2 = bin2dec(s2);
        
        love = gcd(n1, n2);

        if(love > 1) cout << "Pair #" << i + 1 << ": All you need is love!" << endl;
        else cout << "Pair #" << i + 1 << ": Love is not all you need!" << endl; 
    }

    return 0;
}

int bin2dec(string str) {
    int size = str.length();
    int tmp = 1;
    int sum = 0;

    for(int i = size - 1; i >= 0; i--) {
        sum = sum + tmp * (str[i] - '0');
        tmp = tmp * 2;
    }

    return sum;
}

int gcd(int n1, int n2)
{
    int nBig = (n1 > n2) ? n1 : n2;
    int nSmall = (n1 < n2) ? n1 : n2;
    int tmp = 0;

    while(nSmall != 0) {
        tmp = nSmall;
        nSmall = nBig % nSmall;
        nBig = tmp;
    }

    return nBig;
}
