#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        bool valid = true;
        int N; cin >> N;
        vector<long long> S(N);
        for (int i = 0; i < N; i++) cin >> S[i];

        if (2 * S[0] >= S[N - 1]) {
            cout << 2 << endl;
            continue;
        }

        sort(S.begin() + 1, S.end() - 1);

        long long ans = 2;
        long long power = S[0] * 2;
        int idx = 1;
        while (power < S[N - 1]) {
            ans++;
            long long nextPower = power;
            int nextIdx = idx;
            for (int i = idx; i < N - 1; i++) {
                if (S[i] > power) {
                    break;
                }
                nextPower = max(nextPower, S[i] * 2);
                nextIdx = i + 1;
            }
            if (nextPower == power) {
                cout << -1 << '\n';
                valid = false;
                break;
            }
            power = nextPower;
            idx = nextIdx;
        }
        if (!valid) continue;
        cout << ans << '\n';
    }

    return 0;
}
