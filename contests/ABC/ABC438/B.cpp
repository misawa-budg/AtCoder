#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    string S, T; cin >> S >> T;

    int res = INT_MAX;
    for (int i = 0; i <= S.size() - T.size(); i++) {
        int count = 0;
        for (int j = 0; j < T.size(); j++) {
            if (T[j] > S[i + j]) count += (S[i + j] + 10) - T[j];
            else count += S[i + j] - T[j];
        }
        res = min(res, count);
    }
    cout << res << '\n';

    return 0;
}
