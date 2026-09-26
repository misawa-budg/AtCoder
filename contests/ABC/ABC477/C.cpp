#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q; cin >> Q;
    string S, T; cin >> S >> T;

    int N = S.size(), M = T.size();
    vector<int> sum(N + 1);

    for (int i = 0; i < N; i++) {
        bool ok = (i + M <= N);

        if (ok) {
            for (int j = 0; j < M; j++) {
                if (S[i + j] != T[j]) { ok = false; break; }
            }
        }

        sum[i + 1] = sum[i] + ok;
    }

    while (Q--) {
        int L, R; cin >> L >> R;
        L--; R--;

        if (R - L + 1 < M) {
            cout << "No\n";
            continue;
        }

        int right = R - M + 1;

        if (sum[right + 1] - sum[L] > 0) cout << "Yes\n";
        else cout << "No\n";
    }

    return 0;
}
