#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, Q; cin >> N >> M >> Q;
    vector<set<int>> perm(N + 1);
    vector<int> all(N + 1);

    for (int i = 0; i < Q; i++) {
        int t; cin >> t;
        if (t == 1) {
            int x, y; cin >> x >> y;
            perm[x].insert(y);
        } else if (t == 2) {
            int x; cin >> x;
            all[x] = 1;
        } else if (t == 3) {
            int x, y; cin >> x >> y;
            if (all[x] == 1 || perm[x].count(y)) {
                cout << "Yes" << '\n';
            } else {
                cout << "No" << '\n';
            }
        }
    }


    return 0;
}
