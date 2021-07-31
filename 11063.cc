/* UVa 11063 B2-Sequence */
/* 2021/4/29 Wendy */

#include <iostream>
#include <set>
using namespace std;

int main()
{
    int N;
    int B2[10000];
    set<int> sum;
    int count = 0;
    int flag;

    while(cin >> N) {
        count++;
        flag = 0;
        cin >> B2[0];
        if(B2[0] == 0) flag = 1;
        for(int i = 1; i < N; i++) {
            cin >> B2[i];
            if(B2[i] < B2[i - 1]) flag = 1;  
        }

        if(flag == 0) {
            sum.clear();
            for(int i = 0; i < N; i++) {
                for(int j = i; j < N; j++) {
                    sum.insert(B2[i] + B2[j]);
                }
            }
        }

        if(sum.size() != (1 + N) * N / 2) flag = 1;
        if(flag == 0) cout << "Case #" << count << ": It is a B2-Sequence." << endl << endl;
        else cout << "Case #" << count << ": It is not a B2-Sequence." << endl << endl;
    }

    return 0;
}