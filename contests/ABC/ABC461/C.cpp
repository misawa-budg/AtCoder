#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K, M; cin >> N >> K >> M;
    vector<long long> C(N), V(N);
    for (int i = 0; i < N; i++) cin >> C[i] >> V[i];

    map<long long, multiset<long long, greater<long long>>> mp;
    for (int i = 0; i < N; i++) {
        mp[C[i]].insert(V[i]);
    }

    vector<long long> first, remain;

    long long result = 0;
    for (const auto &itr : mp) {
        auto msItr = itr.second.begin();
        first.push_back(*msItr);
        msItr++;

        while (msItr != itr.second.end()) {
            remain.push_back(*msItr);
            msItr++;
        }
    }

    sort(first.begin(), first.end(), greater<long long>());

    for (int i = 0; i < M; i++) result += first[i];
    for (int i = M; i < first.size(); i++) remain.push_back(first[i]);

    sort(remain.begin(), remain.end(), greater<long long>());
    for (int i = 0; i < K - M; i++) result += remain[i];

    cout << result << '\n';

    return 0;
}
