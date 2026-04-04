#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;
    string T; cin >> T;

    int N = S.size();
    int M = T.size();
    vector<vector<int>> nextIdx(N+1, vector<int>(26, N));

    for (int i = N - 1; i >= 0; i--) {
        for (int c = 0; c < 26; c++) {
            nextIdx[i][c] = nextIdx[i+1][c];
        }
        nextIdx[i][S[i] - 'a'] = i;
    }

    long long ans = 0;
    
    for (int l = 0; l < N; l++) {
        int cur = l;
        bool completed = true;

        for (int k = 0; k < M; k++) {
            int target = T[k] - 'a';
            cur = nextIdx[cur][target];

            if (cur == N) {
                completed = false;
                break;
            }

            cur++;
        }

        if (completed) {
            ans += (cur - 1 - l);
        } else {
            ans += (N - l);
        }
    }

    cout << ans << '\n';

    return 0;
}
