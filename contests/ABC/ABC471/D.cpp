#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long Q; long long V; cin >> Q >> V;

    priority_queue<long long> pq;
    while (Q--) {
        long long query; cin >> query;
        if (query == 1) {
            long long t, w; cin >> t >> w;
            pq.push(w - t);
        } else if (query == 2) {
            long long t; cin >> t;
            if (pq.empty()) {
                cout << -1 << '\n';
                continue;
            }

            long long top = pq.top(); pq.pop();
            cout << min(V, t + top) << '\n';
        }
    }

    return 0;
}
