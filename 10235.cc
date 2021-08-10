/* ★☆☆ UVa 10235 Simply Emirp */
/* 2021/8/3 Wendy */

#define N 1000000

#include <iostream>
#include <math.h>
#include <string>
using namespace std; 

int string2reverse(string str);

int main()
{
    int table[N + 1] = {0};
    int n = 0;
    int S = (int)sqrt(N);
    string str;
    int num = 0;
    int reverse = 0;

    for(int i = 2; i <= S; i++) {
        if(table[i] == 1) continue;

        n = 2;
        while(i * n <= N) {
            table[i * n] = 1;
            n++;
        }
    }

    while(cin >> str) {
        num = stoi(str);
        reverse = string2reverse(str); 

        /* An Emirp is a Prime that gives you a "different Prime" when its digits are reversed */
        if(table[num] == 1) cout << num << " is not prime." << endl;
        else if(table[num] == 0 && num == reverse) cout << num << " is prime." << endl;
        else if(table[num] == 0 && table[reverse] == 0) cout << num << " is emirp." << endl;
        else cout << num << " is prime." << endl;
    }

    return 0;
}

int string2reverse(string str) 
{
    int size = str.length();
    int tmp = 1;
    int sum = 0;

    for(int i = 0; i < size; i++) {
        if(str[size - 1 - i] != '0') {
            size = size - i;
            break;
        }
    }

    for(int i = 0; i < size; i++) {
        sum = sum + (str[i] - '0') * tmp;
        tmp = tmp * 10;
    }

    return sum;
}