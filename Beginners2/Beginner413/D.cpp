#include <bits/stdc++.h>
using namespace std;
using i128 = __int128_t;

void solve() {
    int n; cin >> n;
    vector<long long> A(n);
    unordered_map<long long, pair<int,int>> cnt;
    cnt.reserve(n * 2);

    int pos = 0, neg = 0;
    for (int i = 0; i < n; ++i) {
        long long x; cin >> x;
        if (x > 0) ++pos; else ++neg;
        long long a = llabs(x);
        A[i] = a;
        auto &p = cnt[a];
        if (x > 0) ++p.first; else ++p.second;
    }

    sort(A.begin(), A.end());

    bool geo = true;
    for (int i = 2; i < n && geo; ++i)
        if (A[i]*A[i-2] != A[i-1]*A[i-1]) geo = false;
    if (!geo) {
        cout << "No\n";
        return;
    }

    if (pos == n || neg == n) { cout << "Yes\n"; return; }

    bool ok = false;
    for (int fs = 1; fs >= -1 && !ok; fs -= 2) {
        auto rem = cnt;
        bool good = true;
        for (int i = 0; i < n && good; ++i) {
            int need = (i % 2 == 0 ? fs : -fs);
            auto &p = rem[A[i]];
            if (need > 0) {
                if (p.first == 0) good = false;
                else --p.first;
            } else {
                if (p.second == 0) good = false;
                else --p.second;
            }
        }
        if (good) ok = true;
    }

    cout << (ok ? "Yes\n" : "No\n");
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        solve();
    }

    return 0;
}
