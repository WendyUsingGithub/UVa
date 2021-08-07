/* ★☆☆ UVa 10642 Can You Solve It? */
/* 2021/8/8 */

#include <iostream>
using namespace std;

#define N 100000

long long circlesBetween(int srcXY, int dstXY);

int main()
{
    int T = 0;
    int srcX = 0;
    int srcY = 0;
    int dstX = 0;
    int dstY = 0;
    int srcXY = 0;
    int dstXY = 0;
    int steps = 0;

    cin >> T;
    for(int t = 0; t < T; t++) {
        cin >> srcX >> srcY >> dstX >> dstY;
        srcXY = srcX + srcY;
        dstXY = dstX + dstY;

        if(srcXY == dstXY) steps = srcY - dstY;
        else steps = srcY + circlesBetween(srcXY, dstXY) + dstX + 1;
        cout << "Case " << t + 1 << ": " << steps << endl;
    }
}

long long circlesBetween(int srcXY, int dstXY)
{
    /* XY lines between srcXY and dstXY */
    srcXY = srcXY + 1;
    dstXY = dstXY - 1;

    /* there are XY + 1 circles on each line XY */
    srcXY++;
    dstXY++;

    return (srcXY + dstXY) * (dstXY - srcXY + 1) / 2;
}