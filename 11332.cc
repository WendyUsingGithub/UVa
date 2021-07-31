/* UVa 11332 Summing Digits */
/* 2021/4/22 Wendy */

#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;
    int sum;
    int len;

    while(1) {
        cin >> str;
        if(str.length() == 1 && str[0] == '0') return 0;

        while(str.length() > 1) {
            sum = 0;
            for(int i = 0; i < str.length(); i++) {
                sum  = sum + (str[i] - '0');
            }
            str = to_string(sum);
        }
        cout << str << endl;
    }

    return 0;
}
