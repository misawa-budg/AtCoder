#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<int> covered(N + 2, 0);
    for (int i = 0; i < M; i++) {
        int L, R; cin >> L >> R;
        covered[L]++;
        covered[R + 1]--;
    }

    int cur = 0, ans = INT_MAX;
    for (int i = 1; i <= N; i++) {
        cur += covered[i];
        ans = min(ans, cur);
    }

    cout << ans << endl;

    return 0;
}
