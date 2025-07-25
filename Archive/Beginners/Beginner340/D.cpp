#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N - 1);
    vector<vector<pair<int, long long>>> B(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b, x; cin >> a >> b >> x;
        x--;
        A[i] = a;
        B[i].push_back({A[i], i + 1});
        B[i].push_back({b, x});
    }

    vector<long long> dist(N, LLONG_MAX);
    priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>
    > pq;
    dist[0] = 0;
    pq.push({0, 0});
    while (!pq.empty()) {
        auto [cost, node] = pq.top(); pq.pop();
        if (dist[node] < cost) continue;
        for (auto [next_cost, next] : B[node]) {
            if (dist[next] > cost + next_cost) {
                dist[next] = cost + next_cost;
                pq.push({dist[next], next});
            }
        }
    }

    cout << dist[N - 1] << endl;



    return 0;
}
