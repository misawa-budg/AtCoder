#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    long long D; cin >> D;
    vector<pair<long long, int>> X(N);
    for (int i = 0; i < N; i++) {
        long long x; cin >> x;
        X[i] = make_pair(x, i + 1);
    }

    sort(X.begin(), X.end());

    vector<int> ans;

    for (int i = 0; i < N; i++) {
        bool ok = true; 
        if (i) {
            if (X[i].first - X[i-1].first < D) ok = false;
        }
        
        if (i != N - 1) {
            if (X[i + 1].first - X[i].first < D) ok = false;
        }

        if (ok) {
            ans.push_back(X[i].second);
        }
    }

    cout << ans.size() << '\n';
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ' ';
    }
    cout << '\n';

    return 0;
}
