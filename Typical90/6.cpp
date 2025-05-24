#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; cin >> N >> K;
    string S; cin >> S;

    vector<vector<int>> nearestIndex(N + 1, vector<int>(26, -1));
    for (int i = N - 1; i >= 0; i--) {
        nearestIndex[i] = nearestIndex[i + 1];
        nearestIndex[i][S[i] - 'a'] = i;
    }

    string ans = "";
    int cur = 0;
    for (int i = 0; i < K; i++) {
        for (char c = 'a'; c <= 'z'; c++) {
            int idx = nearestIndex[cur][c - 'a'];
            if (idx != -1 && ((N - idx) >= (K - i))) {
                ans += c;
                cur = idx + 1;
                break;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
