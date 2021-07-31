/* UVA 12019 Doom's Day Algorithm */
/* 2021/4/23 Wendy */

#include <iostream>
using namespace std;

int main()
{
    int n;
    int mDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    string weekDay[7] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    int m, d;
    int days;
    int W0101, w;

    days = 31 + 28 + 31 + 4 - 1; /* 4/4 Monday */
    W0101 = 7 - (days % 7); /* (W0101 + days) % 7 = 0; */

    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> m >> d;
        days = 0;
        for(int j=0; j<m-1; j++) {
            days = days + mDays[j];
        }
        days = days + d -1 ;
        w = (W0101 + days) % 7;
        cout << weekDay[w] << endl;
    }
    
    return 0;
}