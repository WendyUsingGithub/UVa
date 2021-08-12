/* ★☆☆ UVa 118 Mutant Flatworld Explorers */
/* 2021/8/12 Wendy */

#include <iostream>
using namespace std;

#define X 0
#define Y 1

int main()
{
    int Height = 0;
    int Width = 0;
    int x = 0;
    int y = 0;
    int field[51][51] = {0};
    string str;
    string faces = "NESW";
    int movements[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int face = 0;
    int len = 0;
    int lost = 0;
    
    /* the first line of input is the upper-right coordinates of the rectangular world */
    cin  >> Width >> Height;
    while(cin >> x >> y >> str) {
        face = faces.find(str[0]);
        getchar();
        getline(cin, str);
        len = str.length();
        lost = 0;
        
        for(int i = 0; i < len; i++) {
            if(str[i] == 'L') {
                face = face - 1;
                if(face == -1) face = 3;
            }
            if(str[i] == 'R') {
                face = face + 1;
                if(face == 4) face = 0;
            }
            if(str[i] == 'F') {
                if(x + movements[face][X] >= 0 && x + movements[face][X] <= Width && 
                        y + movements[face][Y] >= 0 && y + movements[face][Y] <= Height) {
                    x = x + movements[face][X];
                    y = y + movements[face][Y];
                }
                else {
                    /* an instruction to move “off” the world from a grid point from which a robot has been
                     * previously lost is simply ignored by the current robot. */
                    if(field[x][y] == 1) continue;
                    /* move off from edge*/
                    else {
                        field[x][y] = 1;
                        lost = 1;
                        break;
                    }
                }
            }
        }
        
        cout << x << " " << y << " " << faces[face];
        if(lost == 1) cout << " LOST" << endl;  
        else cout << endl;
    }

    return 0;
}
