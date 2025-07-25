#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L; cin >> N >> L;
    vector<long long> position(N, 0);
    for (int i = 0; i < N - 1; i++) {
        int d; cin >> d;
        position[i + 1] = (position[i] + d) % L;
    }

    // 3分割できるはず
    if (L % 3 != 0) {
        cout << "0" << endl;
        return 0;
    }
    long long part = L / 3;

    // d = 0があるらしい
    vector<long long> count(L, 0);
    for (int i = 0; i < N; i++) {
        count[position[i]]++;
    }

    long long ans = 0;
    for (int i = 0; i < L; i++) {
        if (count[i] == 0) continue;
        long long next = (i + part) % L;
        long long next2 = (i + 2 * part) % L;
        if (count[next] == 0 || count[next2] == 0) continue;
        if (i < next && i < next2) {
            ans += count[i] * count[next] * count[next2];
        }
    }

    cout << ans << endl;

    return 0;
}
