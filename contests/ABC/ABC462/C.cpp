#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<pair<int, int>> coordinates(N);
    for (int i = 0; i < N; i++) {
        cin >> coordinates[i].first >> coordinates[i].second;
    }

    sort(coordinates.begin(), coordinates.end(), [&](auto x, auto y) {
        if (x.first != y.first) return x.first < y.first;
        else return y.first < y.second;
    });

    int maxY = INT_MAX;
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (maxY > coordinates[i].second) {
            maxY = coordinates[i].second;
            count++;
        }
    }
    
    cout << count << '\n';

    return 0;
}
