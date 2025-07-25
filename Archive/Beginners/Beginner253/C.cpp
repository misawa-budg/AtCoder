#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q; cin >> Q;

    map<int, int> S;
    while (Q--) {
        int query; cin >> query;
        if (query == 1) {
            int x; cin >> x;
            S[x]++;
        } else if (query == 2) {
            int x, c; cin >> x >> c;
            if (S.count(x)) {
                S[x] -= min(c, S[x]);
                if (S[x] == 0) S.erase(x);
            }
        } else {
            auto biggest = S.rbegin();
            auto smallest = S.begin();
            cout << (biggest->first - smallest->first) << '\n';
        }
    }

    return 0;
}
