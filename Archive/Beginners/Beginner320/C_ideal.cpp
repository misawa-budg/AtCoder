#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int M; cin >> M;
    string S1, S2, S3; cin >> S1 >> S2 >> S3;
    int ans = LLONG_MAX;

    for (int i = 0; i < 3 * M; i++) {
        for (int j = 0; j < 3 * M; j++) {
            for (int k = 0; k < 3 * M; k++) {
                if (i != j && j != k && i != k
                    && S1[i % M] == S2[j % M] && S2[j % M] == S3[k % M]) {
                        ans = min(ans, max({i, j, k}));
                    }
            }
        }
    }
    cout << (ans == LLONG_MAX ? -1 : ans) << endl;

    return 0;
}
