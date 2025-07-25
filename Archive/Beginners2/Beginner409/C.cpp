#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L; cin >> N >> L;
    vector<int> d(N - 1); for (int i = 0; i < N - 1; i++) cin >> d[i];

    if (L % 3 != 0) {
        cout << 0 << endl;
        return 0;
    }

    vector<int> pos(N, 0);
    for (int i = 0; i < N - 1; i++) {
        pos[i + 1] = (pos[i] + d[i]) % L;
    }

    vector<int> cnt(L, 0);
    for (int i = 0; i < N; i++) cnt[pos[i]]++;

    long long ans = 0;
    for (int i = 0; i < L / 3; i++) {
        long long first = cnt[i];
        long long second = cnt[i + L / 3];
        long long third = cnt[i + 2 * L / 3];

        ans += first * second * third;
    }
    cout << ans << endl;

    return 0;
}
