#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; cin >> N >> K;
    long long total = 0;
    map<long long, long long> sums_map; 
    
    for (int i = 0; i < N; i++) {
        long long A; cin >> A;
        sums_map[A] += A;
        total += A;
    }

    vector<long long> sums;
    for (auto p : sums_map) {
        sums.push_back(p.second);
    }

    sort(sums.rbegin(), sums.rend());

    int limit = min(K, (int)sums.size());
    for (int i = 0; i < limit; i++) {
        total -= sums[i];
    }

    cout << total << '\n';
    return 0;
}
