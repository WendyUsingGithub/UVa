/* ★☆☆ UVa 10908 Largest Square */
/* 2021/8/4 Wendy */

#include <iostream>
using namespace std; 

int calStepMax(int r, int c, int M, int N);

int main()
{
    int T = 0;
    int M = 0;
    int N = 0;
    int Q = 0;
    int r = 0;
    int c = 0;
    char table[100][100] = {0};
    char rc = 0;
    int step = 0;
    int stepMax = 0;
    bool flag = false;
    int leftColumn = 0;
    int rightColumn = 0;
    int topRow = 0;
    int bottomRow = 0;

    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> M >> N >> Q;
        cout << M << " " << N << " " << Q << endl;
        for(int m = 0; m < M; m++) {
            for(int n = 0; n < N; n++) {
                cin >> table[m][n];
            }
        }

        for(int q = 0; q < Q; q++) {
            cin >> r >> c;
            rc = table[r][c];

            /* input boundary check */
            if(r < 0 || r >= M || c < 0 || c >= N) {
                cout << "0" << endl;
                continue;
            }

            /* out of boundry check */
            stepMax = calStepMax(r, c, M, N);

            flag = false;        
            for(step = 1; step <= stepMax; step++) {
                topRow = r - step;
                bottomRow = r + step;
                rightColumn = c + step;
                leftColumn = c - step;
                for(int i = -step; i <= step; i++) {
                    /* top row */
                    if(table[topRow][c + i] != rc) {
                        flag = true;
                        break;
                    }
                    /* bottom row */
                    if(table[bottomRow][c + i] != rc) {
                        flag = true;
                        break;
                    }
                    /* right column */
                    if(table[r + i][rightColumn] != rc) {
                        flag = true;
                        break;
                    }
                    /* left column */
                    if(table[r + i][leftColumn] != rc) {
                        flag = true;
                        break;
                    }
                }
                if(flag == true) break;
            }
            
            step--;
            cout << 2 * step + 1 << endl;
        }
    }

    return 0;
}

int calStepMax(int r, int c, int M, int N)
{
    int a = M - r - 1;
    int b = N - c - 1;
    int m = r;

    if(c < m) m = c;
    if(a < m) m = a;
    if(b < m) m = b;

    return m;
}