#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;
    vector<int> query(Q), p(Q);
    vector<string> S(Q);
    for (int i = 0; i < Q; i++) {
        cin >> query[i] >> p[i];
        if (query[i] == 2) {
            cin >> S[i];
            reverse(S[i].begin(), S[i].end());
        }
    }

    string ans;
    int i = 0;
    for (int t = Q - 1; t >= 0; t--) {
        if (query[t] == 1) {
            if (i == p[t]) {
                i = 0;
            }
        } else if (query[t] == 2) {
            if (i == p[t]) {
                ans += S[t];
            }
        } else {
            if (i == 0) {
                i = p[t];
            }
        }
    }
    reverse(ans.begin(), ans.end());

    cout << ans << '\n';

    return 0;
}
