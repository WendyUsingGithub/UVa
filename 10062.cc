/* ★☆☆ UVa 10062 Tell me the frequencies! */
/* 2021/8/10 Wendy */

#include <iostream>
#include <string>
#include <cstring>
using namespace std;

struct data {
    int c;
    int freq;
};

int compare(const void* aPtr, const void* bPtr);

int main()
{
    string str;
    struct data table[256];
    int len = 0;
    int firstLine = 0;

    while(getline(cin, str)) {
        if(firstLine == 1) cout << endl;
        if(firstLine == 0) firstLine = 1;

        for(int i = 0; i < 256; i++) {
            table[i].c = i;
            table[i].freq = 0;
        }
        len = str.length();
        for(int i =0; i < len; i++) {
            table[str[i]].freq++;
        }

        /* input will contain none of the first 32 or last 128 ASCII characters. */
        qsort(table + 32, 256 - 32 - 128, sizeof(struct data), compare);

        for(int i = 32; i < 128; i++) {
            if(table[i].freq == 0) continue;
            cout << (int)table[i].c << " " << table[i].freq << endl;
        }
    }

    return 0;
}

int compare(const void* aPtr, const void* bPtr)
{
    struct data a = *(struct data*)aPtr;
    struct data b = *(struct data*)bPtr;

    if(a.freq < b.freq) return 0;
    else if(a.freq == b.freq && a.c > b.c) return 0;
    else return 1;
}