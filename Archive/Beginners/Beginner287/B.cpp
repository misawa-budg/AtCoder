#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<string> S(N); for (int i = 0; i < N; ++i) cin >> S[i];
    set<string> T;
    for (int i = 0; i < M; ++i) {
        string t; cin >> t;
        T.insert(t);
    }

    int ans = 0;
    for (int i = 0; i < N; i++) {
        string suffix = S[i].substr(S[i].size() - 3);
        if (T.count(suffix)) ans++;
    }
    cout << ans << endl;

    return 0;
}
