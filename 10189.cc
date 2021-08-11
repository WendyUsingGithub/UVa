/* ★☆☆ UVa 10189 Minesweeper */
/* 2021/8/11 Wendy */

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int M = 0;
    int N = 0;
    int field[101][101] = {0};
    char c;
    int count = 0;

    while(cin >> M >> N) {
        if(M == 0 && N == 0) return 0;
        if(count != 0) cout << endl;
        count++;

        memset(field, 0, sizeof(int) * 101 * 101);
        for(int i = 1; i <= M; i++) {
            for(int j = 1; j <= N; j++) {
                cin >> c;
                if(c == '*') {
                    field[i][j] = -9; /* almost surrounded by 8 miles */
                    for(int p = -1; p <= 1; p++) {
                        for(int q = -1; q <= 1; q++) {
                            field[i + p][j + q]++;
                        }
                    }
                }
            }
        }

        cout << "Field #" << count << ":" << endl;
        for(int i = 1; i <= M; i++) {
            for(int j = 1; j <= N; j++) {
                if(field[i][j] < 0) cout << "*";
                else cout << field[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}