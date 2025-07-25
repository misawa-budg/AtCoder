#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> P(N); for (int i = 0; i < N; i++) cin >> P[i];

    int maxP = 0;
    for (int i = 1; i < N; i++) {
        maxP = max(maxP, P[i]);
    }

    cout << max(0, maxP - P[0] + 1) << endl;

    return 0;
}
