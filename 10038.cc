/* ★☆☆ UVa 10038 Jolly Jumpers */
/* 2021/4/23 Wendy */

#include <iostream>
#include <set>
using namespace std;

int main()
{
    int n;
    int arr[3000];
    set<int> jolly;

    while(cin >> n) {
        for(int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        for(int i = 1; i < n; i++) {
            if(abs(arr[i] - arr[i-1]) < n) jolly.insert(abs(arr[i] - arr[i-1]));
        }

        if(jolly.size() == (n - 1)) cout << "Jolly" << endl;
        else cout << "Not jolly" << endl;

        jolly.clear();
    }

    return 0;
}