#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<int> R(M), C(M);
    for (int i = 0; i < M; i++) {
        cin >> R[i] >> C[i];
    }

    set<pair<int, int>> isused;
    vector<short> dx = {0, 1, 0, 1};
    vector<short> dy = {0, 0, 1, 1};

    long long ans = 0;
    for (int i = 0; i < M; i++) {
        int startR = R[i], startC = C[i];
        bool can = true;
        for (int j = 0; j < 4; j++) {
            int useR = startR + dy[j];
            int useC = startC + dx[j];
            if (isused.contains(make_pair(useR, useC))) {
                can = false;
                break;
            }
        }

        if (can) {
            for (int j = 0; j < 4; j++) {
                int useR = startR + dy[j];
                int useC = startC + dx[j];
                isused.insert(make_pair(useR, useC));
            }
            ans++;
        }
    }

    cout << ans << '\n';

    return 0;
}
