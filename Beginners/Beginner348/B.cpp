#include <bits/stdc++.h>
using namespace std;

double CalculateEuclideanDistance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<pair<int, int>> points(N);
    for (int i = 0; i < N; i++) {
        cin >> points[i].first >> points[i].second;
    }

    for (int i = 0; i < N; i++) {
        double maxDistance = 0;
        int maxIndex = -1;
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            double distance = CalculateEuclideanDistance(points[i].first, points[i].second, points[j].first, points[j].second);
            if (distance > maxDistance) {
                maxDistance = distance;
                maxIndex = j;
            }
        }
        cout << maxIndex + 1 << endl;
    }

    return 0;
}
