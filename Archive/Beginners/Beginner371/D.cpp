#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> villages(N);
    vector<long long> populations(N);
    for (int i = 0; i < N; i++) cin >> villages[i];
    for (int i = 0; i < N; i++) cin >> populations[i];
    vector<long long> populationDp(N, 0LL);
    populationDp[0] = populations[0];
    for (int i = 1; i < N; i++) populationDp[i] = populationDp[i-1] + populations[i];

    int Q;
    cin >> Q;

    for (int i = 0; i < Q; i++) {
        int L, R;
        cin >> L >> R;

        int leftVillage = lower_bound(villages.begin(), villages.end(), L) - villages.begin();
        int rightVillage = upper_bound(villages.begin(), villages.end(), R) - villages.begin() - 1;

        if (rightVillage < leftVillage) {
            cout << 0 << endl;
        } else if (leftVillage == rightVillage) {
            cout << populations[leftVillage] << endl;
        } else {
            long long ans = populationDp[rightVillage] - ((leftVillage == 0) ? 0 : populationDp[leftVillage - 1]);
            cout << ans << endl;
        }
    }

    return 0;
}
