#include <bits/stdc++.h>
#include "atcoder/dsu.hpp"
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    atcoder::dsu uf(N);

    for (int i = 0; i < M; i++) {
        int a, b; cin >> a >> b;
        uf.merge(a - 1, b - 1);
    }

    int ideal = 0;
    for (auto& group : uf.groups()) {
        ideal += group.size() - 1;
    }

    cout << M - ideal << endl;

    return 0;
}
