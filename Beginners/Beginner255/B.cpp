#include <bits/stdc++.h>
using namespace std;

double calc_dist(int x1, int y1, int x2, int y2) {
    long long dx = x1 - x2;
    long long dy = y1 - y2;

    double result = sqrt(dx * dx + dy * dy);
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; cin >> N >> K;
    vector<int> A(K + 1); for (int i = 1; i <= K; i++) cin >> A[i];
    vector<pair<int, int>> points(N + 1);
    for (int i = 1; i <= N; i++) {
        cin >> points[i].first >> points[i].second;
    }

    double ans = 0.0;
    for (int i = 1; i <= N; i++) {
        double dist = 1e9;
        for (int j = 1; j <= K; j++) {
            dist = min(dist, calc_dist(points[i].first, points[i].second, points[A[j]].first, points[A[j]].second));
        }
        ans = max(ans, dist);
    }

    cout << fixed << setprecision(12) << ans << '\n';

    return 0;
}
