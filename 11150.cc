/* ★☆☆ UVa 11150 Cola */
/* 2021/10/13 Wendy */

#include <iostream>
using namespace std;

int calCola(int N);

int main()
{
    int N = 0;

    while(cin >> N) {
        cout << calCola(N + 1) - 1 << endl;
    }

    return 0;
}

int calCola(int N)
{
    int sum = 0;
    int dividend = 0;
    int quotient = 0;
    int remainder = 0;

    dividend = N;
    sum = N;
    do {
        quotient = dividend / 3;
        remainder = dividend % 3;
        dividend = quotient + remainder;
        sum = sum + quotient;
    } while(quotient > 0);

    return sum;
}