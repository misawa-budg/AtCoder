#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<long long> X(N);
    for (auto &x : X) cin >> x;
    sort(X.begin(), X.end());

    if (M >= N) {
        cout << 0 << '\n';
        return 0;
    }

    vector<long long> gap;
    gap.reserve(N - 1);
    for (int i = 0; i < N - 1; ++i) gap.push_back(X[i + 1] - X[i]);

    sort(gap.rbegin(), gap.rend());

    long long cut_sum = 0;
    for (int i = 0; i < M - 1; ++i) cut_sum += gap[i];

    long long ans = (X.back() - X.front()) - cut_sum;
    cout << ans << '\n';
    return 0;
}
