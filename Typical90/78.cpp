#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<vector<int>> smallerAdj(N + 1);

    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        if (a > b) smallerAdj[a].push_back(b);
        else smallerAdj[b].push_back(a);
    }

    int ans = 0;
    for (int i = 0; i < N+1; i++) {
        if (smallerAdj[i].size() == 1) ans++;
    }

    cout << ans << endl;

    return 0;
}
