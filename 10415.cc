/* ★☆☆ UVa 10415 Eb Alto Saxophone Player */
/* 2021/8/12 Wendy */

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string notes = "cdefgabCDEFGAB";
    string noteFingers[15] = {
        "0111001111", /* c */
        "0111001110", /* d */
        "0111001100", /* e */
        "0111001000", /* f */
        "0111000000", /* g */
        "0110000000", /* a */
        "0100000000", /* b */  
        "0010000000", /* C */
        "1111001110", /* D */
        "1111001100", /* E */
        "1111001000", /* F */
        "1111000000", /* G */
        "1110000000", /* A */
        "1100000000", /* B */
        "0000000000"  /* 0 */
    };
    int N = 0;
    string str;
    int len = 0;
    int currentNote = 0;
    int lastNote = 0;
    int table[15][15][10] = {0};
    int stats[10] = {0};

    for(int i = 0; i < 15; i++) { /* lastNote */
        for(int j = 0; j < 15; j++) { /* currentNode */
            for(int k = 0; k < 10; k++) {
                if(noteFingers[i][k] == '0' && noteFingers[j][k] == '1') table[i][j][k] = 1;
            }
        }
    }

    cin >> N;
    getchar();
    for(int i = 0; i < N; i++) {
        memset(stats, 0, sizeof(int) * 10);
        getline(cin, str);
        len = str.length();
        currentNote = 14;
        for(int i = 0; i < len; i++) {
            lastNote = currentNote;
            currentNote = notes.find(str[i]);
            for(int j = 0; j < 10; j++) {
                if(table[lastNote][currentNote][j] == 1) stats[j]++;
            }
        }
        
        for(int i = 0; i < 10; i++) {
            cout << stats[i];
            if(i != 9) cout << " ";
        }
        cout << endl;
    }

    return 0;
}
