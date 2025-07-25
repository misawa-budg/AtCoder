#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> D(N); for (int i = 1; i < N; i++) cin >> D[i];
    vector<int> cumulative(N + 1, 0);
    for (int i = 2; i <= N; i++) {
        cumulative[i] = cumulative[i - 1] + D[i - 1];
    } // cumulative[i] は i番目の駅までの距離の合計

    for (int i = 1; i < N; i++) {
        for (int j = i + 1; j <= N; j++) {
            int distance = cumulative[j] - cumulative[i];
            cout << distance << ' ';
        }
        cout << '\n';
    }

    return 0;
}
