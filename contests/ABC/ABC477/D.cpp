#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;

    vector<int> type(Q), x(Q);
    vector<char> c(Q);
    vector<bool> tile(N, false);

    for (int i = 0; i < Q; i++) {
        cin >> type[i];

        if (type[i] == 1) {
            cin >> x[i]; x[i]--;
            tile[x[i]] = !tile[x[i]];
        } else {
            cin >> c[i];
        }
    }

    set<int> noTile;
    for (int i = 0; i < N; i++)
        if (!tile[i]) noTile.insert(i);

    string ans(N, '?');
    for (int i = Q - 1; i >= 0; i--) {
        if (type[i] == 1) {
            int p = x[i];
            tile[p] = !tile[p];

            if (ans[p] != '?') continue;

            if (tile[p]) noTile.erase(p);
            else noTile.insert(p);
        } else {
            for (int p : noTile) ans[p] = c[i];
            noTile.clear();
        }
    }

    for (int i = 0; i < N; i++) {
        if (ans[i] == '?') ans[i] = 'a';
    }

    cout << ans << '\n';

    return 0;
}
