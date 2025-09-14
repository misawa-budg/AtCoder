#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, K; cin >> N >> K;
    vector<long long> A(N + 1), B(N + 1), C(N + 1);
    for (int i = 1; i <= N; i++) cin >> A[i] >> B[i] >> C[i];

    vector<long long> enter(N + 1, -1);
    queue<int> q;
    priority_queue<
        pair<long long, int>,
        vector<pair<long long, int>>,
        greater<pair<long long, int>>
    > pq;

    long long current = 0, t = 0;
    int idx = 1, done = 0;

    while (done < N) {
        long long nextCustomer = (idx <= N ? A[idx] : LLONG_MAX);
        long long nextFinish = (!pq.empty() ? pq.top().first : LLONG_MAX);
        long long nextEvent = min(nextCustomer, nextFinish);

        t = nextEvent;

        // たいてん -> 到着 -> 入店
        while (!pq.empty() && pq.top().first == t) {
            int id = pq.top().second; pq.pop();
            current -= C[id];
        }

        while (idx <= N && A[idx] == t) {
            q.push(idx);
            idx++;
        }

        while (!q.empty()) {
            int id = q.front();
            if (current + C[id] <= K) {
                enter[id] = t;
                current += C[id];
                pq.emplace(t + B[id], id);
                q.pop();
                done++;
            } else {
                break;
            }
        }

    }

    for (int i = 1; i <= N; i++) {
        cout << enter[i] << "\n";
    }

    return 0;
}
