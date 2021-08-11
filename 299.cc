/* ★☆☆ UVa 299 Train Swapping */
/* 2021/8/11 Wendy */

#include <iostream>
using namespace std;

int main()
{
    int T = 0;
    int L = 0;
    int trains[50];
    int t = 0;
    int swap = 0;

    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> L;
        for(int j = 0; j < L; j++) {
            cin >> trains[j];
        }

        swap = 0;
        for(int j = 0; j < L; j++) {
            t = trains[j];
            for(int k = j + 1; k < L; k++) {
                if(t > trains[k]) swap++;
            }
        }
        cout << "Optimal train swapping takes " << swap << " swaps." << endl;
    }

    return 0;
}