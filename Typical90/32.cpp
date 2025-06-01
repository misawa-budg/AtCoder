#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<vector<int>> person_cost(N, vector<int>(N, 0));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> person_cost[i][j];
        }
    }

    int M; cin >> M;
    vector<vector<int>> dislike_pairs(10, vector<int>(10, 0));
    vector<int> order(N);
    for (int i = 0; i < N; i++) order[i] = i;
    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b; a--, b--;
        dislike_pairs[a][b] = 1;
        dislike_pairs[b][a] = 1;
    }

    int ans = INT_MAX;
    do {
        int cost = 0;
        bool valid = true;
        for (int i = 0; i < N-1; i++) {
            if (dislike_pairs[order[i]][order[i+1]]) valid = false;
        }
        for (int i = 0; i < N; i++) {
            cost += person_cost[order[i]][i];
        }
        if (valid) ans = min(ans, cost);
    } while (next_permutation(order.begin(), order.end()));

    cout << (ans == INT_MAX ? -1 : ans) << endl;

    return 0;
}
