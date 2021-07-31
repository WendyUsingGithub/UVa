/* UVA 490 Rotating Sentences */
/* 2021/4/22 Wendy */

#include <iostream>
#include <string.h>
#include <cstring>
using namespace std;

int main()
{
    char a[100][101];
    int len, lenRow;
    int row;

    memset(a, 0, sizeof(a));

    while(cin.getline(a[row], 101)) {
        lenRow = strlen(a[row]);
        if(lenRow > len) len = lenRow;
        else {
            memset(a[row] + lenRow, ' ', len - lenRow);
        }
        row++;
    }

    for(int j = 0; j < len; j++) {
        for(int i = row - 1; i >= 0; i--) {
            if(a[i][j] == 0) {
                break;
            }
            cout << a[i][j];
        }
        cout << endl;
    }

    return 0;
}


