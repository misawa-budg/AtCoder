#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;
    vector<multiset<int>> S(200001);
    vector<set<int>> T(200001);
    
    for (int i = 0; i < Q; i++) {
        int query, x; cin >> query >> x;

        if (query == 1) {
            int y; cin >> y;
            S[y].insert(x);
            T[x].insert(y);
        } else if (query == 2) {
            for (auto it = S[x].begin(); it != S[x].end(); it++) {
                cout << *it << " ";
            }
            cout << endl;
        } else {
            for (auto it = T[x].begin(); it != T[x].end(); it++) {
                cout << *it << " ";
            }
            cout << endl;
        }
    }

    return 0;
}