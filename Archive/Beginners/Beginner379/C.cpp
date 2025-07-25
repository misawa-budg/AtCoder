#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M; cin >> N >> M;
    vector<int> X(M), A(M);
    vector<pair<long long, long long>> stones(M);
    long long total = 0, value = 0;

    for (int i = 0; i < M; i++) cin >> stones[i].first;
    for (int i = 0; i < M; i++) {
        cin >> stones[i].second;
        total += stones[i].second;
        value += stones[i].first * stones[i].second;
    }

    if (total != N) {
        cout << -1 << endl;
        return 0;
    }

    sort(stones.begin(), stones.end());

    long long cumulative = 0;
    for (int i = 0; i < M; i++) {
        if (cumulative + 1 < stones[i].first) {
            cout << -1 << endl;
            return 0;
        }
        cumulative += stones[i].second;
    }

    long long lastVal = 0;
    if (N % 2 == 0) {
        lastVal = N / 2;
        lastVal *= (N + 1);
    } else {
        lastVal = (N + 1) / 2;
        lastVal *= N;
    }
    long long ans = lastVal - value;
    cout << ans << endl;

    return 0;
}
