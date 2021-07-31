/* UVA 272 TEX Quotes */
/* 2021/4/23 Wendy */

#include <iostream>
using namespace std;

int main()
{
    string str;
    int len;
    int count;

    while(getline(cin, str)) {
        len = str.length();
        for(int i = 0; i < len; i++) {
            if(str[i] == '"') {
                if(count % 2 == 0) cout << "``";
                else cout << "''";
                count++;
            }
            else cout << str[i];
        }
        cout << endl;
    }

    return 0;
}