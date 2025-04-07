#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    long long X, Y;
    cin >> N >> X >> Y;

    vector<int> sweets(N);
    vector<int> salty(N);
    for (int i = 0; i < N; i++) {
        cin >> sweets[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> salty[i];
    }

    long long totalSweet = 0, totalSalty = 0;

    // 一番食べる量が少なくなる場合を探す = 甘さorしょっぱさが速く基準値を超える

    sort(sweets.rbegin(), sweets.rend());
    sort(salty.rbegin(), salty.rend());

    for (int i = 0; i < N; i++) {
        totalSweet += sweets[i];
        totalSalty += salty[i];

        if (totalSweet > X || totalSalty > Y) {
            cout << i + 1 << endl;
            return 0;
        }
    }

    cout << N << endl;

    return 0;
}
