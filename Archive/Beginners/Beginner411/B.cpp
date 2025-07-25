#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> D(N - 1);
    for (int i = 0; i < N - 1; i++) {
        cin >> D[i];
    }

    vector<int> cumulative(N, 0);
    for (int i = 0; i < N - 1; i++) {
        cumulative[i + 1] = cumulative[i] + D[i];
    } // cumulative[i] は 駅 i までの距離の合計

    for (int i = 0; i < N - 1; i++) {
        for (int j = i + 1; j < N; j++) {
            cout << cumulative[j] - cumulative[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
