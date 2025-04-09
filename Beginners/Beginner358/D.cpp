#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<int> A(N);
    vector<int> B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < M; i++) cin >> B[i];

    multiset<int> s;
    for (int i = 0; i < N; i++) s.insert(A[i]);

    long long cost = 0;
    for (int i = 0; i < M; i++) {
        auto it = s.lower_bound(B[i]);
        if (it == s.end()) {
            cout << -1 << endl;
            return 0;
        } else {
            cost += *it;
            s.erase(it);
        }
    }

    cout << cost << endl;

    return 0;
}
