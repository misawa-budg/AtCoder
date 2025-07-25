#include <bits/stdc++.h>
using namespace std;

double calculateEuclideanDistance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D; cin >> N >> D;
    vector<pair<int, int>> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].first >> points[i].second;
    }
    vector<int> canBePolluted(N, 0);
    canBePolluted[0] = 1;
    deque<pair<int, int>> q;
    q.push_back(points[0]);

    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop_front();
        for (int i = 0; i < N; i++) {
            if (points[i] == make_pair(x, y)) continue;
            if (canBePolluted[i] == 1) continue;
            double distance = calculateEuclideanDistance(x, y, points[i].first, points[i].second);
            if (distance <= D) {
                canBePolluted[i] = 1;
                q.push_back(points[i]);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (canBePolluted[i] == 1) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
