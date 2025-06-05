#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    const int MOD = 46;
    vector<int> ACnt(MOD, 0), BCnt(MOD, 0), CCnt(MOD, 0);
    for (int i = 0; i < N; i++) {
        int a; cin >> a;
        ACnt[a % MOD]++;
    }
    for (int i = 0; i < N; i++) {
        int b; cin >> b;
        BCnt[b % MOD]++;
    }
    for (int i = 0; i < N; i++) {
        int c; cin >> c;
        CCnt[c % MOD]++;
    }

    long long ans = 0;
    for (int i = 0; i < MOD; i++) {
        for (int j = 0; j < MOD; j++) {
            int k = (MOD - (i + j) % MOD) % MOD;
            ans += 1LL * ACnt[i] * BCnt[j] * CCnt[k];
        }
    }
    cout << ans << endl;

    return 0;
}
