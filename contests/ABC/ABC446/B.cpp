#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;

    vector<bool> isused(M + 1, false);
    for (int i = 0; i < N; i++) {
        int len; cin >> len;
        vector<int> juice(len);
        for (int j = 0; j < len; j++) {
            cin >> juice[j];
        }

        int ans = 0;
        for (int j = 0; j < len; j++) {
            if (!isused[juice[j]]) {
                ans = juice[j];
                isused[juice[j]] = true;
                break;
            }
        }
        cout << ans << '\n';
    }

    return 0;
}
