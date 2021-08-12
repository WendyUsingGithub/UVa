/* ★☆☆ UVa 10409 Die Game */
/* 2021/8/12 Wendy */

#include <iostream>
using namespace std;

int main()
{
    int top = 1;
    int north = 2;
    int west = 3;
    int bottom = 6;
    int south = 5;
    int east = 4;
    int tmp = 0;
    int N = 0;
    string dir;

    while(1) {
        cin >> N;
        if(N == 0) break;
        top = 1;
        north = 2;
        west = 3;
        bottom = 6;
        south = 5;
        east = 4;

        for(int i = 0; i < N; i++) {
            cin >> dir;

            if(dir == "west") {
                tmp = west;
                west = top;
                top = east;
                east = bottom;
                bottom = tmp;
            }
            if(dir == "east") {
                tmp = east;
                east = top;
                top = west;
                west = bottom;
                bottom = tmp;
            }
            if(dir == "north") {
                tmp = north;
                north = top;
                top = south;
                south = bottom;
                bottom = tmp;
            }
            if(dir == "south") {
                tmp = south;
                south = top;
                top = north;
                north = bottom;
                bottom = tmp;
            }
        }
        cout << top << endl;
    }

    return 0;
}