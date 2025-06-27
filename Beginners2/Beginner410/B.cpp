#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;
    vector<int> X(Q); for (int i = 0; i < Q; i++) cin >> X[i];
    vector<int> cnt(N + 1, 0);

    for (int i = 0; i < Q; i++) {
        int box = -1;
        if (X[i] >= 1) {
            cnt[X[i]]++;
            box = X[i];
        } else {
            int minCnt = *min_element(cnt.begin() + 1, cnt.end());
            for (int j = 1; j <= N; j++) {
                if (cnt[j] == minCnt) {
                    box = j;
                    cnt[j]++;
                    break;
                }
            }
        }
        if (i) cout << " ";
        cout << box;
    } cout << '\n';

    return 0;
}
