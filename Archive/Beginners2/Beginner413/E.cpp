#include <bits/stdc++.h>
using namespace std;

void dfs(vector<int>& p, int l, int len) {
    if (len == 1) return;
    int h = len >> 1;

    dfs(p, l, h); // 左
    dfs(p, l + h, h); // 右

    for (int i = 0; i < h; ++i) {
        if (p[l + i] == p[l + h + i]) continue;
        if (p[l + i] > p[l + h + i]) {
            for (int j = 0; j < h; ++j)
                swap(p[l + j], p[l + h + j]);
        }
        break;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        int n = 1 << N;
        vector<int> p(n); for (int i = 0; i < n; ++i) cin >> p[i];

        dfs(p, 0, n);

        for (int i = 0; i < n; ++i) {
            if (i) cout << ' ';
            cout << p[i];
        }
        cout << '\n';
    }
    return 0;
}
