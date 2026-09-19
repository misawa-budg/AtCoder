#include <bits/stdc++.h>
#include "atcoder/segtree.hpp"
using namespace std;
using namespace atcoder;

using S = pair<int, int>;

S opMin(S a, S b) { return min(a, b); }
S eMin() { return {INT_MAX, -1}; }

S opMax(S a, S b) { return max(a, b); }
S eMax() { return {INT_MIN, -1}; }

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<int> P(N);
    vector<S> V(N);
    for (int i = 0; i < N; i++) {
      cin >> P[i];
      V[i] = {P[i], i};
    }

    segtree<S, opMin, eMin> segMin(V);
    segtree<S, opMax, eMax> segMax(V);

    for (;M > 0;M--) {
      int L, R; cin >> L >> R; L--;

      auto mn = segMin.prod(L, R), mx = segMax.prod(L, R);
      int i = mn.second, j = mx.second;

      swap(P[i], P[j]);

      segMin.set(i, {P[i], i}); segMin.set(j, {P[j], j});
      segMax.set(i, {P[i], i}); segMax.set(j, {P[j], j});
    }

    for (int i = 0; i < N; i++) {
      cout << P[i] << ' ';
    } cout << '\n';

    return 0;
}
