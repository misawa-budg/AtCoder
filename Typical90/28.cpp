#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    const int LIMIT = 1000;
    vector<vector<int>> diff(LIMIT + 2, vector<int>(LIMIT + 2, 0));
    for (int i = 0; i < N; i++) {
        int lx, ly, rx, ry;
        cin >> lx >> ly >> rx >> ry;
        diff[ly][lx]++;
        diff[ly][rx]--;
        diff[ry][lx]--;
        diff[ry][rx]++;
    }

    for (int i = 0; i <= LIMIT; i++) {
        for (int j = 1; j <= LIMIT; j++) {
            diff[i][j] += diff[i][j-1];
        }
    }

    for (int i = 1; i <= LIMIT; i++) {
        for (int j = 0; j <= LIMIT; j++) {
            diff[i][j] += diff[i-1][j];
        }
    }

    vector<int> ans(N + 1, 0);
    for (int i = 0; i < LIMIT; i++) {
        for (int j = 0; j < LIMIT; j++) {
            ans[diff[i][j]]++;
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << "\n";
    }

    return 0;
}
