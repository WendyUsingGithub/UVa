/* UVa 10252 Common Permutation */
/* 2021/4/22 Wendy */

#include <iostream>
using namespace std;

int main()
{
    string str1, str2;
    int count, count1[26], count2[26];
    int len1, len2;

    while(getline(cin, str1) && getline(cin, str2)) {
        for(int i = 0; i < 26; i++) {
            count1[i] = 0;
            count2[i] = 0;
        }

        len1 = str1.length();
        len2 = str2.length();

        for(int i = 0; i < len1; i++) {
            count1[str1[i] - 'a']++;
        }
        for(int i = 0; i < len2; i++) {
            count2[str2[i] - 'a']++;
        }

        for(int i = 0; i < 26; i++) {
            count = (count1[i] >= count2[i]) ?  count2[i] : count1[i];
            for(int j = 0; j < count; j++) {
                cout << (char)(i + 'a');
            }
        }
        cout << endl;
    }
    
    return 0;
}


