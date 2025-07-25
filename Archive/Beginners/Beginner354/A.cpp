#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H;
    cin >> H;

    long long plantHeight = 0;
    int day = 0;
    while (plantHeight <= H) {
        plantHeight += 1 << day;
        day++;
    }

    cout << day << endl;

    return 0;
}
