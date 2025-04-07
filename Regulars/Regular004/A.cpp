#include <bits/stdc++.h>
#include <iomanip>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<pair<int, int>> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].first >> points[i].second;
    }

    double ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;

            int xDiff = points[i].first - points[j].first;
            int yDiff = points[i].second - points[j].second;
            double dist = sqrt(xDiff * xDiff + yDiff * yDiff);
            ans = max(ans, dist);
        }
    }

    cout << fixed << setprecision(6) << ans << endl;

    return 0;
}
