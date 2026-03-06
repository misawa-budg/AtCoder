#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<vector<int>> G(N, vector(N, -1));

    pair<int, int> ld; 
    ld.first = 0; ld.second = (N-1)/2;
    int last = 1;
    G[ld.first][ld.second] = last++;
    for (int i = 0; i < N * N - 1; i++) {
        int targeti = (ld.first-1+N)%N;
        int targetj = (ld.second+1)%N;
        if (G[targeti][targetj] == -1) {
            G[targeti][targetj] = last++;
            ld.first = targeti;
            ld.second = targetj;
        } else {
            G[(ld.first+1)%N][ld.second] = last++;
            ld.first = (ld.first+1) % N;
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (j) cout << ' ';
            cout << G[i][j];
        }
        cout << '\n';
    }

    return 0;
}
