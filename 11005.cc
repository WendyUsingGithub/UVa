/* ★☆☆ UVa 11005 Cheapest Base */
/* 2021/8/1 Wendy */

#include <iostream>
#include <vector>
using namespace std;

int dec2base(int dec, int base, const int *const costTable);

int main()
{
    int C = 0;
    int N = 0;
    int costTable[36] = {0};
    int dec = 0;
    int cost = 0;
    int cheapestCost = 0;
    vector<int> cheapestBase;
    int size = 0;

    cin >> C;
    for(int i = 0; i < C; i++) {
        cout << "Case " << i + 1 << ":" << endl;
        for(int j = 0; j < 36; j++) {
            cin >> costTable[j];
        }

        cin >> N;
        for(int j = 0; j < N; j++) {
            cin >> dec;
            cheapestCost = dec2base(dec, 2, costTable);
            cheapestBase.clear();
            cheapestBase.push_back(2);
            for(int k = 3; k <= 36; k++) {
                cost = dec2base(dec, k, costTable);
                if(cost == cheapestCost) {
                    cheapestBase.push_back(k);
                }
                if(cost < cheapestCost) {
                    cheapestCost = cost;
                    cheapestBase.clear();
                    cheapestBase.push_back(k);
                }
            }
            cout << "Cheapest base(s) for number " << dec << ": ";
            size = cheapestBase.size();
            for(int k = 0; k < size - 1; k++) {
                cout << cheapestBase[k] << " ";
            }
            cout << cheapestBase[size - 1] << endl;
        }
        if(i != C - 1) cout << endl;
    }
}

int dec2base(int dec, int base, const int *const costTable)
{
    int tmp = 0;
    int cost = 0;

    while(dec != 0) {
        tmp = dec % base;
        cost = cost + costTable[tmp];
        dec = dec / base;
    }

    return cost;
}