/* UVA 10268 498-bis */
/* 2021/4/26 Wendy */

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s, str;
    stringstream ss;
    int x, n;
    vector<long long> a;
    int size;
    long long xPoly;
    long long sum;
    
    while(cin >> x) {
        getchar();
        getline(cin, s);
        ss.clear();
        a.clear();
        
        ss << s;
        while(ss >> str) {
            n = stoi(str);
            a.push_back(n);
        }
     
        size = a.size();
        for(int i = 0; i < size; i++) {
            a[i] = a[i] * (size - i - 1);
          
        }

        a.pop_back();
        size = a.size();
        xPoly = 1;
        sum = 0;
        for(int i = size-1; i >= 0; i--) {
            sum = sum +  a[i] * xPoly;
            xPoly = xPoly * x; 
        }
        cout << sum << endl;
    }

    return 0;
}

