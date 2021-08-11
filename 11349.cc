/* ★☆☆ UVa 11349 Symmetric Matrix */
/* 2021/4/27 Wendy */

#include <iostream>
using namespace std;

int main()
{
    int numC;
    char c;
    int N;
    long long M[101][101];
    int flag;
    int middle;

    cin >> numC;
    for(int k = 0; k < numC; k++) {
        cin >> c >> c >> N;
        flag = 0;
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                cin >> M[i][j];
                if(M[i][j] < 0) flag = 1; 
            }
        }

        if(flag == 0) {
            middle = (N % 2 == 0) ? (N / 2 - 1) : (N / 2);
            for(int i = 0; i < N; i++) {
                for(int j = 0; j <= middle; j++) {
                    if(M[i][j] != M[N - 1 -i][N - 1 - j]) {
                        flag = 1;
                        i = N;
                        break;
                    }
                }
            }
        }

        if(flag == 0) cout << "Test #" << k + 1 << ": " << "Symmetric." << endl;
        if(flag == 1) cout << "Test #" << k + 1 << ": " << "Non-symmetric." << endl;        
    }
    
    return 0;
}