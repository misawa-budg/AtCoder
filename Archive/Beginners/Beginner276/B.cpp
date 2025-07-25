#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<set<int>> connected(N + 1);
    for (int i = 0; i < M; ++i) {
        int a, b; cin >> a >> b;
        connected[a].insert(b);
        connected[b].insert(a);
    }

    for (int i = 1; i <= N; i++) {
        cout << connected[i].size() << " ";
        for (auto &num : connected[i]) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
