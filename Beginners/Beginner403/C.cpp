#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M, Q; cin >> N >> M >> Q;
    vector<set<int>> permissions(N + 1);
    vector<int> all(N + 1, 0);

    for (int i = 0; i < Q; i++) {
        int query, user; cin >> query >> user;
        if (query == 1) {
            int page; cin >> page;
            permissions[user].insert(page);
        } else if (query == 2) {
            all[user]++;
        } else {
            int page; cin >> page;
            if (all[user] > 0 || permissions[user].count(page)) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}
