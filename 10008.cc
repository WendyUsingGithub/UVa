/* UVA 10008 What's Cryptanalysis? */
/* 2021/4/21 Wendy */

#include <iostream>
#include <cctype>
using namespace std;

int compare(const void *a, const void *b);

struct data  {
    char c;
    int freq;
};

int main()
{
    int N;
    char c;
    struct data alphabet[26];

    for(int i = 0; i < 26; i++) {
        alphabet[i].c = i;
        alphabet[i].freq = 0;
    }

    cin >> N;
    while(cin >> c) {
        c = toupper(c);
        if(c >= 'A' || c <= 'Z') alphabet[c - 'A'].freq++;
    }

    qsort(alphabet, 26, sizeof(struct data), compare);

    for(int i = 0; i < 26; i++) {
        if(alphabet[i].freq == 0) break;
        cout << (char)('A' + alphabet[i].c) << " " << alphabet[i].freq << endl;
    }

    return 0;
}

/* 
   若 a 的 priority 較大 -> return 1 (a 放右邊)
   若 a 的 priority 較小 -> return 0 (a 放左邊)
   qsort 的排序是由 priority 小 排到 priority 大 
*/

int compare(const void *a, const void *b)
{
    struct data data_a = *(struct data *)a;
    struct data data_b = *(struct data *)b;

    if(data_a.freq > data_b.freq) return 0;
    else if(data_a.freq < data_b.freq) return 1;
    else if(data_a.freq == data_b.freq) {
        if(data_a.c < data_b.c) return 0;
        return 1;
    }             
}