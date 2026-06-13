#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;

    vector<vector<int>> given(N + 1);

    for (int i = 0; i < N; i++) {
        int K; cin >> K;
        for (int j = 1; j <= K; j++) {
            int to; cin >> to;
            given[to].push_back(i+1);
        }
    }

    for (int i = 1; i <= N; i++) {
        cout << given[i].size();
        if (given[i].size() == 0) {
            cout << '\n';
            continue;
        } else cout << ' ';
        for (int j = 0; j < given[i].size(); j++) {
            if (j) cout << ' ';
            cout << given[i][j];
        }
        cout << '\n';
    }


    return 0;
}
