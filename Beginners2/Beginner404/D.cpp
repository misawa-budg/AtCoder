#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<int> C(N); for (int i = 0; i < N; i++) cin >> C[i];
    vector<vector<int>> animals(M);
    for (int i = 0; i < M; i++) {
        int K; cin >> K;
        for (int j = 0; j < K; j++) {
            int place; cin >> place; place--;
            animals[i].push_back(place);
        }
    }

    int maxMask = 1;
    for (int i = 0; i < N; i++) maxMask *= 3;

    long long ans = LLONG_MAX;
    vector<int> cnt(N, 0);
    for (int mask = 0; mask < maxMask; mask++) {
        int tmp = mask;
        for (int i = 0; i < N; i++) {
            cnt[i] = tmp % 3;
            tmp /= 3;
        }

        bool ok = true;
        for (int i = 0; i < M; i++) {
            int count = 0;
            for (int index : animals[i]) {
                count += cnt[index];
            }
            if (count < 2) {
                ok = false;
                break;
            }
        }

        if (ok) {
            long long cost = 0;
            for (int i = 0; i < N; i++) {
                cost += 1LL * C[i] * cnt[i];
            }
            ans = min(ans, cost);
        }
    }
    cout << ans << '\n';

    return 0;
}
