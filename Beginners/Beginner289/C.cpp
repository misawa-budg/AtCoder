#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<vector<int>> counter(M, vector<int>(N + 1, 0));
    for (int i = 0; i < M; i++) {
        int num; cin >> num;
        for (int j = 0; j < num; j++) {
            int a; cin >> a;
            counter[i][a]++;
        }
    }

    int ans = 0;
    for (int bit = 1; bit < (1 << M); bit++) {
        vector<int> cnt(N + 1, 0);
        for (int i = 0; i < M; i++) {
            if (bit & (1 << i)) {
                for (int j = 1; j <= N; j++) {
                    cnt[j] += counter[i][j];
                }
            }
        }

        bool ok = true;
        for (int i = 1; i <= N; i++) {
            if (cnt[i] == 0) {
                ok = false;
                break;
            }
        }

        if (ok) ans++;
    }
    cout << ans << endl;

    return 0;
}
