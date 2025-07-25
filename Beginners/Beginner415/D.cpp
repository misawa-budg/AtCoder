#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, M; cin >> N >> M;
    vector<pair<long long, long long>> bottles(M);
    for (int i = 0; i < M; i++) {
        long long A, B; cin >> A >> B;
        bottles[i] = {A - B, A}; // cost, required
    }

    sort(bottles.begin(), bottles.end());
    long long ans = 0;
    long long remain = N;
    for (const auto& [cost, required] : bottles) {
        if (required > remain) continue;
        long long count = (remain - required) / cost + 1;
        ans += count;
        remain -= count * cost;
    }
    cout << ans << endl;

    return 0;
}
