#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<set<int>> pairs(N);
    for (int i = 0; i < M; i++) {
        int K; cin >> K;
        vector<int> people(K);
        for (int j = 0; j < K; j++) {
            cin >> people[j];
        }
        for (int j = 0; j < K - 1; j++) {
            for (int k = j + 1; k < K; k++) {
                pairs[people[j] - 1].insert(people[k] - 1);
                pairs[people[k] - 1].insert(people[j] - 1);
            }
        }
    }

    bool ok = true;
    for (int i = 0; i < N; i++) {
        if (pairs[i].size() != N - 1) {
            ok = false;
            break;
        }
    }

    cout << (ok ? "Yes" : "No") << '\n';

    return 0;
}
