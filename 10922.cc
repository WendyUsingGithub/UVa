/* ★☆☆ UVa 10922 2 the 9s */
/* 2021/8/4 Wendy */

#include <iostream>
#include <string>
using namespace std; 

int str2s(string str);

int main()
{
    string str;
    string N;
    int n = 0;
    int degree = 0;
    int S = 0;
    int isNine = 0;

    while(1) {
        cin >> N;
        str = N;
        if(str == "0") break;
        isNine = 0;
        degree = 0;
        
        while(1) {
            S = str2s(str);
            if(S % 9 != 0) break;
            else degree++;
            if(S == 9) break;
            str = to_string(S);
        }

        if(degree == 0) cout << N << " is not a multiple of 9." << endl;
        else cout << N << " is a multiple of 9 and has 9-degree " << degree << "." << endl;
    }

    return 0;

}

int str2s(string str)
{
    int size = str.length();
    int sum = 0;

    for(int i = size - 1; i >= 0; i--) {
        sum = sum + (str[i] - '0');
    }

    return sum;
}