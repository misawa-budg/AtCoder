#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;

    vector<int> columns(N + 1, 0);
    vector<int> counts(Q + 1, 0);
    counts[0] = N;

    int offset = 0;

    for (int i = 0; i < Q; i++) {
        int query; cin >> query;

        if (query == 1) {
            int x; cin >> x;

            columns[x]++;
            counts[columns[x]]++;

            if (counts[columns[x]] == N) offset++;

        } else if (query == 2) {
            int y; cin >> y;

            if (y + offset > Q) cout << 0 << '\n';
            else cout << counts[y + offset] << '\n';
        }
    }

    return 0;
}
