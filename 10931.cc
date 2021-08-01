/* UVa 10931 Parity */
/* 2021/8/1 Wendy */

#include <iostream>
#include <vector>
using namespace std;

int dec2bin(int dec, vector<int> *bin);

int main()
{
    int num = 0;
    vector<int> bin;
    int count = 0;
    int size = 0;

    cin >> num;
    while(num != 0) {
        bin.clear();
        count = dec2bin(num, &bin);
        size = bin.size();
        cout << "The parity of ";
        for(int i = 0; i < size; i++) {
            cout << bin[size - 1 - i];
        }
        
        cout << " is " << count << " (mod 2)." << endl; 
        cin >> num;
    }

    return 0;
}

int dec2bin(int dec, vector<int> *bin) 
{
    int tmp = 0;
    int count = 0;

    while(dec != 0) {
        tmp = dec % 2;
        bin->push_back(tmp);
        if(tmp == 1) count++;
        dec = dec / 2;
    }

    return count;
}