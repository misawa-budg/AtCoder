#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, K; cin >> N >> K;
    vector<long long> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
    map<int, long long> day_amount;
    long long total = 0;
    for (int i = 0; i < N; i++) {
        day_amount[A[i] + 1] += B[i];
        total += B[i];
    }

    if (total <= K) {
        cout << 1 << endl;
        return 0;
    }

    long long ans = 0, prev = 0;
    for (auto [day, amount] : day_amount) {
        ans += day - prev;
        total -= amount;
        if (total <= K) break;
        prev = day;
    }
    cout << ans << endl;



    return 0;
}
