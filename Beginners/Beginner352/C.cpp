#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<pair<int, int>> titans(N);
    for (int i = 0; i < N; i++) {
        cin >> titans[i].first >> titans[i].second;
    }

    int diff = 0;
    long long sum = 0;
    for (int i = 0; i < N; i++) {
        diff = max(diff, titans[i].second - titans[i].first);
        sum += titans[i].first;
    }

    cout << sum + diff << endl;

    return 0;
}
