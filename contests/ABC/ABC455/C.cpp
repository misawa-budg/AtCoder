#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; cin >> N >> K;
    vector<long long> A(N); for (int i = 0; i < N; i++) cin >> A[i];
    map<long long, long long> mp;

    for (int i = 0; i < N; i++) {
        mp[A[i]]++;
    }

    vector<long long> sums;
    for (auto [key, value] : mp) {
        sums.push_back(key * value);
    }

    sort(sums.begin(), sums.end());

    long long total = 0;
    for (int i = 0; i < (int) sums.size() - K; i++) {
        total += sums[i];
    }

    cout << total << '\n';

    return 0;
}
