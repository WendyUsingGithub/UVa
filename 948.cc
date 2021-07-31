/* UVa 948 Fibonaccimal Base */
/* 2021/7/31 Wendy */

#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

#define MAX 100000000

void buildFib(vector<int> *fib);
int mostSignificantDigit(int n, const vector<int> *const fib) ;

int main()
{
    vector<int> fib;
    int *nFib;
    int N = 0;
    int num = 0;
    int NUM = 0;
    int msd;
    int MSD;

    cin >> N;
    buildFib(&fib);

    for(int i = 0; i < N; i++) {
        cin >> num;
        NUM = num;
        msd = mostSignificantDigit(num, &fib);
        MSD = msd;
        nFib = (int *)malloc(sizeof(int) * (MSD + 1));
        memset(nFib, 0, sizeof(int) * (MSD + 1));
        nFib[MSD] = 1;
        num = num - fib[MSD];

        while(num > 0) {
            msd = mostSignificantDigit(num, &fib);
            nFib[msd] = 1;
            num = num - fib[msd];
        }

        cout << NUM << " = ";
        for(int j = MSD; j >= 0; j--) {
            cout << nFib[j];
        }
        cout << " (fib)" << endl;
        free(nFib);
    }
}

void buildFib(vector<int> *fib)
{
    int size = 0;
    int tmp = 0;

    fib->clear();
    fib->push_back(1);
    fib->push_back(2);

    while(1) {
        size = fib->size();
        tmp = (*fib)[size - 1] + (*fib)[size - 2];
        fib->push_back(tmp);
        if(tmp >= MAX) break;
    }
}

int mostSignificantDigit(int n, const vector<int> *const fib) 
{
    int size = fib->size();

    for(int i = 0; i < size; i++) {
        if((*fib)[i] > n) return (i - 1);
    }

    return 0;
}