#include <bits/stdc++.h>
#include "atcoder/dsu.hpp"
using namespace std;

long long calculate_manhattan(long long x1, long long y1, long long x2, long long y2) {
    return llabs(x1 - x2) + llabs(y1 - y2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;

    vector<pair<long long, long long>> points;
    for (int i = 0; i < N; ++i) {
        long long x, y; cin >> x >> y;
        points.emplace_back(x, y);
    }

    priority_queue<tuple<long long, int, int>, vector<tuple<long long, int, int>>, greater<>> pq;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            long long dist = calculate_manhattan(points[i].first, points[i].second, points[j].first, points[j].second);
            pq.emplace(dist, i, j);
        }
    }

    atcoder::dsu uf(N + Q + 1);
    long long point_count = N;

    while (Q--) {
        int query; cin >> query;
        if (query == 1) {
            long long x, y; cin >> x >> y;
            points.emplace_back(x, y);
            for (int i = 0; i < point_count; i++) {
                pq.push(make_tuple(calculate_manhattan(points[i].first, points[i].second, x, y), i, point_count));
            }
            point_count++;
        } else if (query == 2) {
            int ans = -1;
            while (!pq.empty()) {
                auto [dist, u, v] = pq.top(); pq.pop();
                if (!uf.same(u, v)) {
                    ans = dist;
                    uf.merge(u, v);
                    while (!pq.empty()) {
                        auto [dist2, u2, v2] = pq.top();
                        if (dist != dist2) break;
                        pq.pop();
                        uf.merge(u2, v2);
                    }
                    break;
                }
            }
            cout << ans << endl;
        } else {
            int x, y; cin >> x >> y;
            cout << (uf.same(x-1, y-1) ? "Yes" : "No") << endl;
        }
    }

    return 0;
}
