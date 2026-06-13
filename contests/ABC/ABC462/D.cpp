#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, D; cin >> N >> D;

    vector<long long> imos(1000001, 0);

    for (int i = 0; i < N; i++) {
        int s, t; cin >> s >> t;

        int end = t - D;
        if (s <= end) {
            imos[s]++;
            imos[end + 1]--;
        }
    }

    long long total = 0;
    for (int i = 1; i <= 1000000; i++) {
        imos[i] += imos[i - 1];
        if (imos[i] >= 2) total += imos[i] * (imos[i] - 1) / 2;
    }

    cout << total << '\n';

    return 0;
}
