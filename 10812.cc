/* UVa 10812 Beat the Spread!*/
/* 2021/4/26 Wendy */

#include <iostream>
using namespace std;

int main()
{
    int a, b;
    int sum, diff;
    int numC;

    cin >> numC;
    for(int i = 0; i < numC; i++) {
        cin >> sum >> diff;
        /* a = (sum + diff) / 2 */
        if((sum + diff) % 2 == 1) {
            cout << "impossible" << endl;
            continue;
        } 
        else a = (sum + diff) / 2;

        b = sum - a;
        if(b < 0) cout << "impossible" << endl;
        else cout << a << " " << b << endl;
    }
    
    return 0;
}