#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;
    vector<vector<int>> A(N);
    for (int i = 0; i < N; i++) {
        int L; cin >> L;
        for (int j = 0; j < L; j++) {
            int a; cin >> a;
            A[i].push_back(a);
        }
    }

    for (int i = 0; i < Q; i++) {
        int s, t; cin >> s >> t;
        s--; t--;
        cout << A[s][t] << endl;
    }

    return 0;
}
