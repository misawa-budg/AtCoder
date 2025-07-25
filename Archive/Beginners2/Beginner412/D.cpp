#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<vector<bool>> adj(N, vector<bool>(N, false));
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u][v] = adj[v][u] = true;
    }

    vector<int> p(N);
    iota(p.begin(), p.end(), 0);

    int max_common = 0;

    do {
        int common = 0;
        for (int i = 0; i < N - 1; ++i) {
            if (adj[p[i]][p[i + 1]]) {
                common++;
            }
        }
        if (adj[p[N - 1]][p[0]]) {
            common++;
        }
        max_common = max(max_common, common);

        for (int k = 3; k < N; ++k) {
            if (N - k < 3) continue;

            common = 0;

            for (int i = 0; i < k - 1; ++i) {
                if (adj[p[i]][p[i + 1]]) common++;
            }
            if (adj[p[k - 1]][p[0]]) common++;

            for (int i = k; i < N - 1; ++i) {
                if (adj[p[i]][p[i + 1]]) common++;
            }
            if (adj[p[N - 1]][p[k]]) common++;

            max_common = max(max_common, common);
        }

    } while (next_permutation(p.begin(), p.end()));

    cout << M + N - 2 * max_common << endl;

    return 0;
}
