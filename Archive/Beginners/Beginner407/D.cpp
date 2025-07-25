#include <bits/stdc++.h>
using namespace std;

struct State {
    long long usedMask;
    long long currentXor;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W;
    cin >> H >> W;
    const int N = H * W;

    vector<long long> value(N);
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j)
            cin >> value[i * W + j];

    vector<vector<int>> neighbor(N);
    for (int i = 0; i < H; ++i)
        for (int j = 0; j < W; ++j) {
            int id = i * W + j;
            if (j + 1 < W) neighbor[id].push_back(id + 1);
            if (i + 1 < H) neighbor[id].push_back(id + W);
        }

    long long allXor = 0;
    for (long long x : value) allXor ^= x;

    long long bestScore = 0;
    stack<State> st;
    st.push({0, allXor});
    while (!st.empty()) {
        State cur = st.top(); st.pop();
        if (cur.usedMask == (1 << N) - 1) {
            bestScore = max(bestScore, cur.currentXor);
            continue;
        }

        int i = 0;
        while (cur.usedMask & (1 << i)) ++i;
        st.push({cur.usedMask | (1 << i), cur.currentXor});

        for (int j : neighbor[i]) {
            if (cur.usedMask & (1 << j)) continue;
            long long newMask = cur.usedMask | (1 << i) | (1 << j);
            long long newXor = cur.currentXor ^ value[i] ^ value[j];
            st.push({newMask, newXor});
        }
    }

    cout << bestScore << '\n';
    return 0;
}
