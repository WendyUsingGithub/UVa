/* ★☆☆ UVa 10057 A mid-summer night's dream. */
/* 2021/8/10 Wendy */

/* why the answer the medium :
 * 
 * for example , a testcase with 7 points
 * ._______.___._______.________._____._________. 
 * p1      p2  p3      p4       p5    p6        p7
 * 
 * we first assume medium is the answer , A is p4
 * ._______.___._______.________._____._________. 
 * p1      p2   p3     p4       p5    p6        p7
 *                     ^
 *                     A
 * if we move A a little right    
 * ._______.___._______.________._____._________. 
 * p1      p2  p3      p4       p5    p6        p7
 *                         ^
 *                         A         
 * for p1 , p2 , p3 , p4 , A becomes farer
 * for p5 , p6 , p7 , A becomes closer
 * it's apparently now that , there will be no better answer than medium
 */

#include <iostream>
using namespace std;

#define N 1000000

int compare(const void *a, const void *b);
int numbersBetween(int* numbers, int n, int mediumLeft, int mediumRight);

int main()
{
    int n = 0;
    int numbers[N];
    int mediumLeft = 0;
    int mediumRight = 0;

    while(cin >> n) {
        for(int i = 0; i < n; i++) {
            cin >> numbers[i];
        }

        qsort(numbers, n, sizeof(int), compare);

        if(n % 2 == 1) {
            mediumLeft = numbers[n / 2];
            mediumRight = numbers[n / 2];
        }
        else {
            mediumLeft = numbers[n / 2 - 1];
            mediumRight = numbers[n / 2]; 
        }

        cout << mediumLeft << " ";
        cout << numbersBetween(numbers, n, mediumLeft, mediumRight) << " ";
        cout << mediumRight - mediumLeft + 1 << endl;
    }
}

/* if priority a > priority b return 1 */
int compare(const void* aPtr, const void* bPtr)
{
    int a = *(int *)aPtr;
    int b = *(int *)bPtr;

    if(a > b) return 1;
    else return 0;
}

int numbersBetween(int* numbers, int n, int mediumLeft, int mediumRight)
{
    int count = 0;

    for(int i = 0; i < n; i++) {
        if(numbers[i] >= mediumLeft && numbers[i] <= mediumRight) count++;
    }

    return count;
}