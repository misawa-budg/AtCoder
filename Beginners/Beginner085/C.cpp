#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Y;
    cin >> N >> Y;

    for (int i = 0; i <= Y / 10000; i++) {
        for (int j = 0; j <= (Y - i * 10000) / 5000; j++) {
            int k = N - i - j;
            if (k < 0) continue;
            if (Y == i * 10000 + j * 5000 + k * 1000) {
                cout << i << " " << j << " " << k << endl;
                return 0;
            }
        }
    }

    cout << "-1 -1 -1" << endl;

    return 0;
}
