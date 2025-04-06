#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    int count = 0;
    map<pair<int, int>, int> mp;

    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        if (u == v) {
            count ++;
            continue;
        }
        if (u > v) {
            swap(u, v);
        }
        mp[{u, v}]++;
    }

    for (auto& [edge, cnt] : mp) count += cnt - 1;

    cout << count << endl;

    return 0;
}
