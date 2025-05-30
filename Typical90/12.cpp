#include <bits/stdc++.h>
#include "atcoder/dsu.hpp"
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W; cin >> H >> W;
    int Q; cin >> Q;

    vector<char> red(H * W, 0);
    atcoder::dsu uf(H * W);
    auto index = [&](int r, int c) {
        return r * W + c;
    };
    const int dx[] = {0, 1, 0, -1};
    const int dy[] = {1, 0, -1, 0};

    for (int i = 0; i < Q; i++) {
        int query; cin >> query;
        if (query == 1) {
            int r, c; cin >> r >> c;
            r--; c--;
            int v = index(r, c);
            red[v] = 1;

            for (int d = 0; d < 4; d++) {
                int nr = r + dy[d], nc = c + dx[d];
                if (nr < 0 || nr >= H || nc < 0 || nc >= W) continue;
                int nv = index(nr, nc);
                if (red[nv]) {
                    uf.merge(v, nv);
                }
            }
        } else {
            int ra, ca, rb, cb;
            cin >> ra >> ca >> rb >> cb;
            ra--; ca--; rb--; cb--;

            int a = index(ra, ca);
            int b = index(rb, cb);
            if (red[a] && red[b] && uf.same(a, b)) {
                cout << "Yes\n";
            } else {
                cout << "No\n";
            }
        }
    }

    return 0;
}