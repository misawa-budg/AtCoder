#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<int> wall(N + 2, 0);
    for (int i = 0; i < M; i++) {
        int l, r; cin >> l >> r;
        wall[l]++;
        wall[r + 1]--;
    }

    for (int i = 1; i <= N; i++) {
        wall[i] += wall[i - 1];
    }

    cout << *min_element(wall.begin() + 1, wall.begin() + N + 1) << endl;

    return 0;
}
