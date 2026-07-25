#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M, D; cin >> M >> D;
    string S; cin >> S;
    vector<bool> covered(M, false);

    for (int i = 0; i < S.size(); i++) {
        if (S[i] == 'G') {
            for (int j = -D; j <= D; j++) {
                int pos = max(0, min(i + j, M - 1));
                covered[pos] = true;
            }
        }
    }

    int ans = 0;
    for (int i = 0; i < M; i++) {
        if (!covered[i]) ans++;
    }

    cout << ans << '\n';

    return 0;
}
