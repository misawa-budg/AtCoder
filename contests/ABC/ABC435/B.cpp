#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];

    vector<int> prefixS(N + 1, 0);
    for (int i = 0; i < N; i++) prefixS[i + 1] = prefixS[i] + A[i];

    long long total = 0;
    for (int l = 1; l <= N; l++) {
        for (int r = l; r <= N; r++) {
            bool ok = true;
            for (int i = l; i <= r; i++) {
                int rangeS = prefixS[r] - prefixS[l - 1];
                if (rangeS % A[i-1] == 0) {
                    ok = false;
                    break;
                }
            }
            if (ok) total++;
        }
    }

    cout << total << '\n';

    return 0;
}
