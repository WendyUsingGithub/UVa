/* ★☆☆ UVa 10226 Hardwood Species */
/* 2021/8/11 Wendy */

#include <iostream>
#include <string.h>
#include <iomanip>
using namespace std;

#define N 1000001

int compare(const void* treeA, const void* treeB);

int main()
{
    int T = 0;
    char *trees = NULL;
    int treeNum = 0;
    int count = 0;

    trees = (char *)malloc(sizeof(char) * N * 31);

    cin >> T;
    getchar();
    getchar();
    for(int i = 0; i < T; i++) {
        treeNum = 0;
        while(1) {
            cin.getline(trees + 31 * treeNum, 31);
            if(*(trees + 31 * treeNum) == 0) break;
            treeNum++;                             
        }

        qsort(trees, treeNum, 31, compare);

        count = 1;
        for(int i = 1; i < treeNum; i++) {
            if(strcmp(trees + 31 * (i - 1), trees + 31 * i) == 0) {
                count++;
            }
            else {
                cout << fixed << setprecision(4) << trees + 31 * (i - 1) << " " << (double)count / treeNum * 100 << endl;
                count = 1;
            }
        }
        cout << fixed << setprecision(4) << trees + 31 * (treeNum - 1) << " " << (double)count / treeNum * 100 << endl;
        if(i != (T - 1)) cout << endl;
    }

    free(trees);
    return 0;
}

int compare(const void* treeA, const void* treeB)
{
    char *A = (char *)treeA;
    char *B = (char *)treeB;

    return strcmp(A, B);
}