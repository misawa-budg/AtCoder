#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    string S; cin >> S;

    vector<int> countX(N + 1, 0);
    for (int i = 0; i < N; i++) {
        countX[i + 1] = countX[i] + (S[i] == 'x' ? 1 : 0);
    }

    for (int k = 1; k <= N; k++) {
        int reach = upper_bound(countX.begin(), countX.end(), k - 1) - countX.begin();
        reach = min(reach, N);
        reach = max(reach, k);

        cout << reach << '\n';
    }

    return 0;
}
