/* UVA 10783 Odd Sum */
/* 2021/4/26 Wendy */

#include <iostream>
using namespace std;

int main()
{
    int a, b;
    int numC;
    int n;

    cin >> numC;
    for(int i = 0; i < numC; i++) {
        cin >> a >> b;
        if(a % 2 == 0) a++;
        if(b % 2 == 0) b--;
        n = (b - a) / 2 + 1;
        cout << "Case " << i + 1 << ": " << (a + b) * n / 2 << endl;
    }
}