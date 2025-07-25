#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<string> C(N); for (int i = 0; i < N; ++i) cin >> C[i];
    vector<string> D(M); for (int i = 0; i < M; ++i) cin >> D[i];
    int exceptPrice; cin >> exceptPrice;
    vector<int> P(M); for (int i = 0; i < M; ++i) cin >> P[i];
    map<string, int> mp;
    for (int i = 0; i < M; i++) {
        mp[D[i]] = P[i];
    }

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        if (mp.find(C[i]) != mp.end()) {
            ans += mp[C[i]];
        } else {
            ans += exceptPrice;
        }
    }
    cout << ans << endl;

    return 0;
}
