#include <bits/stdc++.h>
#include "atcoder/dsu.hpp"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<int> A(M); for (int i = 0; i < M; i++) cin >> A[i];
    atcoder::dsu uf(N);

    for (int i = 0; i < M; i++) {
        uf.merge(A[i] - 1, A[i]);
    }

    for (auto& group : uf.groups()) {
        sort(group.begin(), group.end(), greater<int>());

        for (int i = 0; i < group.size(); i++) {
            if (i) cout << " ";
            cout << group[i] + 1;
        }
        cout << " ";
    }
    cout << endl;

    return 0;
}
