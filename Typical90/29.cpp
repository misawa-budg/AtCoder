#include <bits/stdc++.h>
#include "atcoder/lazysegtree.hpp"
using namespace std;

using S = int;
using F = int;
S op(S a, S b) { return max(a, b); }
S e() { return 0; }
F mapping(F f, S x) { if (f) return f; else return x; }
F composition(F f, F g) { if (f) return f; else return g; }
S id() { return 0; }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int W, N; cin >> W >> N;
    vector<int> V(W, 0);
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(V);

    for (int i = 0; i < N; i++) {
        int L, R; cin >> L >> R; L--, R--;
        int max_height = seg.prod(L, R + 1);
        cout << max_height + 1 << endl;
        seg.apply(L, R + 1, max_height + 1);
    }

    return 0;
}
