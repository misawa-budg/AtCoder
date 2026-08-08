#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q;
    cin >> N >> Q;

    vector<int> P(N + 1);
    vector<int> inv(N + 1);

    for (int i = 1; i <= N; i++) {
        cin >> P[i];
        inv[P[i]] = i;
    }

    bool reversed = false;

    while (Q--) {
        int type;
        cin >> type;
        if (type == 1) {
            int x, y;
            cin >> x >> y;
            if (!reversed) {
                int a = P[x];
                int b = P[y];
                swap(P[x], P[y]);

                inv[a] = y;
                inv[b] = x;
            } else {
                int a = inv[x];
                int b = inv[y];
                swap(inv[x], inv[y]);

                P[a] = y;
                P[b] = x;
            }
        } else {
            reversed = !reversed;
        }
    }

    if (!reversed) {
        for (int i = 1; i <= N; i++) {
            cout << P[i] << (i == N ? '\n' : ' ');
        }
    } else {
        for (int i = 1; i <= N; i++) {
            cout << inv[i] << (i == N ? '\n' : ' ');
        }
    }

    return 0;
}
