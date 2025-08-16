#include <bits/stdc++.h>
#include "atcoder/lazysegtree.hpp"
using namespace std;

struct S1 {
    char s, t;
};
using F = bool;
S1 op(S1 a, S1 b) { return a; }
S1 e() { return S1{0, 0};}
S1 mapping(F f, S1 x) {
    if (f) swap(x.s, x.t);
    return x;
}
F composition(F f, F g) { return f ^ g; }
F id() { return false; }

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    string S, T; cin >> S >> T;

    vector<S1> init(N);
    for (int i = 0; i < N; i++) init[i] = {S[i], T[i]};
    atcoder::lazy_segtree<S1, op, e, F, mapping, composition, id> seg(init);

    while (M--) {
        int L, R; cin >> L >> R; L--;
        seg.apply(L, R, true);
    }

    string ans(N, ' ');
    for (int i = 0; i < N; i++) {
        S1 cha = seg.get(i);
        ans[i] = cha.s;
    }
    cout << ans << endl;

    return 0;
}
