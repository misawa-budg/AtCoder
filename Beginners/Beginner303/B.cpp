#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<set<int>> A(N);
    vector<vector<int>> order(M, vector<int>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            A[i].insert(j);
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> order[i][j];
            order[i][j]--;
        }
    }

    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N - 1; j++) {
            int a = order[i][j], b = order[i][j + 1];
            A[a].erase(b);
            A[b].erase(a);
        }
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans += A[i].size();
    }

    cout << ans / 2 << endl;

    return 0;
}
