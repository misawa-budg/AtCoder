#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;

    vector<int> R(M), C(M);
    for (int i = 0; i < M; i++) {
        cin >> R[i] >> C[i];
        R[i]--; C[i]--;
    }

    vector<bool> rowUsed(N, false), colUsed(N, false);

    int ans = 0;

    for (int i = M - 1; i >= 0; i--) {
        if (!rowUsed[R[i]] && !colUsed[C[i]]) ans++;

        rowUsed[R[i]] = colUsed[C[i]] = true;
    }

    cout << ans << '\n';

    return 0;
}
