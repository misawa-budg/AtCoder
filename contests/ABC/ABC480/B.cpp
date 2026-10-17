#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<string> S(N); for (int i = 0; i < N; i++) cin >> S[i];
    vector<int> ans(N, 0);

    for (int j = 0; j < M; j++) {
        string T; cin >> T;

        int exact = -1;
        for (int i = 0; i < N; i++) {
            if (S[i] == T) {
                exact = i;
                break;
            }
        }

        if (exact != -1) {
            ans[exact]++;
            continue;
        }

        int cnt = 0;
        int candidate = -1;
        for (int i = 0; i < N; i++) {
            if (S[i].size() != T.size()) continue;

            int diff = 0;
            for (int k = 0; k < T.size(); k++) {
                if (S[i][k] != T[k]) diff++;
            }

            if (diff == 1) {
                cnt++;
                candidate = i;
            }
        }

        if (cnt == 1) ans[candidate]++;
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << '\n';
    }

    return 0;
}
