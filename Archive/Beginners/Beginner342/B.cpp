#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> P(N), order(N+1);
    for (int i = 0; i < N; i++) {
        cin >> P[i];
        order[P[i]] = i + 1;
    }

    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        int a, b;; cin >> a >> b;

        if (order[a] > order[b]) {
            cout << b << endl;
        } else {
            cout << a << endl;
        }
    }

    return 0;
}
