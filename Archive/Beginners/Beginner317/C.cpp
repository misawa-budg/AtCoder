#include <bits/stdc++.h>
using namespace std;

int N, M;
vector<vector<pair<int, long long>>> cities;
long long ans = 0;

void dfs(int city, int visited, long long cost)
{
    ans = max(ans, cost);
    for (auto& [next_city, next_cost] : cities[city]) {
        if (visited & (1 << next_city)) continue;
        else {
            dfs(next_city, visited | (1 << next_city), cost + next_cost);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M;
    cities.resize(N);
    for (int i = 0; i < M; i++) {
        int a, b; long long c; cin >> a >> b >> c;
        cities[a - 1].emplace_back(b - 1, c);
        cities[b - 1].emplace_back(a - 1, c);
    }

    int visited = 0;
    for (int i = 0; i < N; i++) {
        dfs(i, visited | (1 << i), 0LL);
    }

    cout << ans << endl;

    return 0;
}
