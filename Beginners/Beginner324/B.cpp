#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N; cin >> N;

    for (__int128_t x = 0; x <= 60; x++) {
        __int128_t xNum = (1LL << x);
        for (__int128_t y = 0; y <= 40; y++) {
            __int128_t yNum = 1;
            for (__int128_t i = 0; i < y; i++) {
                yNum *= 3;
            }
            if (xNum * yNum == N) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}
