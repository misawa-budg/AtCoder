#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, V; cin >> N >> V;
    vector<int> W(N); for (int i = 0; i < N; i++) cin >> W[i];

    int ans = -1;

    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                if (i + j + k + 3 <= V) {
                    ans = max(ans, W[i] + W[j] + W[k]);
                }
            }
        }
    }

    cout << ans << '\n';

    return 0;
}
