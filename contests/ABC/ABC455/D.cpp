#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;
    vector<int> up(2 * N + 1, -1), down(2 * N + 1, -1);

    for (int i = 1; i <= N; i++) {
        up[N + i] = i;
        down[i] = N + i;
    }

    for (int i = 0; i < Q; i++) {
        int c, p; cin >> c >> p;

        up[down[c]] = -1;
        down[c] = p;
        up[p] = c;
    }

    for (int i = 1; i <= N; i++) {
        int base = N + i;
        int ans = 0;

        while (up[base] != -1) {
            base = up[base];
            ans++;
        }

        cout << ans << ((i == N) ? '\n' : ' ');
    }

    return 0;
}
