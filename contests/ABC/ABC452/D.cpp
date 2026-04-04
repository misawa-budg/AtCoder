#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S, T; cin >> S >> T;
    int N = S.length(), M = T.length();

    vector<vector<int>> nextIdx(N + 1, vector<int>(26, N));
    for (int i = N - 1; i >= 0; i--) {
        for (int c = 0; c < 26; c++) {
            nextIdx[i][c] = nextIdx[i + 1][c];
        }
        nextIdx[i][S[i] - 'a'] = i; 
    }

    long long total = 0;
    for (int l = 0; l < N; l++) {
        int cur = l;
        bool completed = true;

        for (int k = 0; k < M; k++) {
            cur = nextIdx[cur][T[k] - 'a'];
            if (cur == N) {
                completed = false;
                break;
            }
            cur++;
        }
        
        if (completed) total += cur - 1 - l;
        else total += N - l; 
    }

    cout << total << '\n';

    return 0;
}
