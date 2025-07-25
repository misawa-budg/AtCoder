#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    map<int, int> mp;
    vector<pair<int, int>> people(N);
    vector<int> P(N+1, 0);
    vector<int> Q(N+1, 0);
    for (int i = 1; i < N + 1; i++) {
        cin >> P[i];
    }
    for (int i = 1; i < N + 1; i++) {
        cin >> Q[i];
    }

    vector<int> ans(N+1, 0);
    for (int i = 1; i < N + 1; i++) {
        ans[Q[i]] = Q[P[i]];
    }

    for (int i = 1; i < N + 1; i++) {
        if (i != 1) {
            cout << " ";
        }
        cout << ans[i];
    }

    return 0;
}
