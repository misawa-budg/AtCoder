#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<pair<long long, int>> places(N);
    for (int i = 0; i < N; i++) {
        cin >> places[i].first >> places[i].second;
    }

    long long ans = 0;
    for (int i = 0; i <= 23; i++) {
        long long sum = 0;
        for (int j = 0; j < N; j++) {
            if (9 <= ((places[j].second + i) % 24) && ((places[j].second + i) % 24) < 18) {
                sum += places[j].first;
            }
        }
        ans = max(ans, sum);
    }

    cout << ans << endl;

    return 0;
}
