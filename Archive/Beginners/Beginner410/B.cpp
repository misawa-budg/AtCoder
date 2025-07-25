#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;
    vector<int> cnt(N + 1, 0);
    vector<int> ans;

    for (int i = 0; i < Q; ++i) {
        int x; cin >> x;
        int box = -1;

        if (x >= 1) {
            box = x;
        } else {
            int bestCnt = INT_MAX;
            for (int j = 1; j <= N; ++j) {
                if (cnt[j] < bestCnt) {
                    bestCnt = cnt[j];
                    box = j;
                }
            }
        }

        cnt[box]++;
        ans.push_back(box);
    }

    for (int i = 0; i < Q; ++i) {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << '\n';

    return 0;
}
