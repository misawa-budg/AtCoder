#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, T; cin >> N >> T;
    vector<int> C(N), R(N);
    for (int i = 0; i < N; i++) cin >> C[i];
    for (int i = 0; i < N; i++) cin >> R[i];

    map<int, set<pair<int, int>, greater<pair<int, int>>>> mp;
    for (int i = 0; i < N; i++) {
        mp[C[i]].insert({R[i], i});
    }

    if (mp.count(T)) {
        auto it = mp[T].begin();
        cout << it->second + 1 << endl;
    } else {
        int color = C[0];
        cout << mp[color].begin()->second + 1 << endl;
    }

    return 0;
}
