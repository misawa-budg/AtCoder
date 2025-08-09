#include <bits/stdc++.h>
using namespace std;

pair<int,int> slope_key(int dx, int dy) {
    if (dx == 0) return {0, 1};
    if (dy == 0) return {1, 0};
    if (dx < 0) { dx = -dx; dy = -dy; }
    int g = std::gcd(abs(dx), abs(dy));
    return {dx / g, dy / g};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> X(N), Y(N);
    for (int i = 0; i < N; ++i) cin >> X[i] >> Y[i];

    unordered_map<long long, long long> slope_cnt;
    unordered_map<long long, long long> mid_cnt;

    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            int dx = X[j] - X[i];
            int dy = Y[j] - Y[i];

            auto s = slope_key(dx, dy);
            long long skey = ( (long long)(uint32_t)s.first << 32 ) | (uint32_t)s.second;
            ++slope_cnt[skey];

            long long mkey = ( (long long)(uint32_t)(X[i] + X[j]) << 32 ) | (uint32_t)(Y[i] + Y[j]);
            ++mid_cnt[mkey];
        }
    }

    long long S = 0;
    for (auto &kv : slope_cnt) {
        long long m = kv.second;
        S += m * (m - 1) / 2;
    }

    long long P = 0;
    for (auto &kv : mid_cnt) {
        long long t = kv.second;
        if (t >= 2) P += t * (t - 1) / 2;
    }

    cout << (S - P) << '\n';
    return 0;
}
