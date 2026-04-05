#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;

    vector<vector<int>> grid(N, vector<int>(N, -1));

    grid[0][(N - 1) / 2] = 1;
    int r = 0, c = (N - 1) / 2, k = 1;

    for (int i = 0; i < N * N - 1; i++) {
        if (grid[(r-1+N)%N][(c+1)%N] == -1) {
            grid[(r-1+N)%N][(c+1)%N] = k + 1;
            r = (r-1+N)%N; c=(c+1)%N; k = k + 1;
        } else {
            grid[(r+1)%N][c] = k + 1;
            r = (r+1)%N; k = k + 1;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j) cout << ' ';
            cout << grid[i][j];
        }
        cout << '\n';
    }

    return 0;
}
