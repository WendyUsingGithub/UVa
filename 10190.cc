/* ★☆☆ UVa 10190 Divide, But Not Quite Conquer! */
/* 2021/8/3 Wendy */

#include <iostream>
#include <vector>
using namespace std; 

int main()
{
    int n = 0;
    int m = 0;
    int boring = 0;
    vector<int> a;
    int size = 0;

    while(cin >> n && cin >> m) {
        a.clear();
        boring = 0;

        /* n == 1 & m == 1 violate requirment a[1] > a[2] > a[3] > . . . > a[k] */
        /* 0 is a valid input since 0 is a non-negative integer */
        if(n == 1 || m == 1 || n == 0 || m == 0) {
            cout << "Boring!" << endl;
        }
        else{
            while(n > 1) {
                if(n % m == 0) {
                    a.push_back(n);
                    n = n / m;
                }
                else {
                    boring = 1;
                    break;
                }
            }

            if(boring == 1) {
                cout << "Boring!" << endl;
            }
            else {
                size = a.size();
                for(int i = 0; i < size; i++) {
                    cout << a[i] << " ";
                }
                cout << "1" << endl;
            }
        }
    }

    return 0;
}

