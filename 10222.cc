/* UVA 10222 Decode the Mad man */
/* 2021/4/21 Wendy */

#include <iostream>
#include <cctype>
#include <string.h>
using namespace std;

int main()
{
    char c;
    char keyboard[] = "qwertyuiop[]" "asdfghjkl;'" "zxcvbnm,.";
    char *ret;

    while(cin.get(c)) {
        c = tolower(c);
        ret = strchr(keyboard, c);
        if(ret) cout << *(ret - 2);
        else cout << c;
    }

    return 0;
}
