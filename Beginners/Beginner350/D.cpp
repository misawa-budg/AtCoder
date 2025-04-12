#include <bits/stdc++.h>
#include "atcoder/dsu.hpp"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    atcoder::dsu uf(N);

    for (int i = 0; i < M; i++) {
        int A, B;
        cin >> A >> B;
        A--; B--;

        uf.merge(A, B);
    }

    long long ans = 0;
    set<int> leaders;
    for (int i = 0; i < N; i++) {
        leaders.insert(uf.leader(i));
    }

    for (auto leader : leaders) {
        int size = uf.size(leader);
        ans += (long long)size * (size - 1) / 2;
    }
    cout << ans - M << endl;


    return 0;
}
