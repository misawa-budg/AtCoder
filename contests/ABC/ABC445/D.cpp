#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int H, W, N; cin >> H >> W >> N;
    vector<int> h(N), w(N);
    for (int i = 0; i < N; i++) {
        cin >> h[i] >> w[i];
    }

    vector<int> ord_h(N), ord_w(N);
    iota(ord_h.begin(), ord_h.end(), 0);
    sort(ord_h.begin(), ord_h.end(), [&](int x, int y) { return h[x] > h[y]; });
    iota(ord_w.begin(), ord_w.end(), 0);
    sort(ord_w.begin(), ord_w.end(), [&](int x, int y) { return w[x] > w[y]; });

    vector<int> ans_x(N), ans_y(N);
    vector<bool> used(N, false);
    auto ith = ord_h.begin();
    auto itw = ord_w.begin();
    for (int rem = N; rem > 0; rem--) {
        while (used[*ith]) ith++;
        while (used[*itw]) itw++;

        int piece = (h[*ith] == H) ? *ith : *itw;
        used[piece] = true;
        ans_x[piece] = H - h[piece] + 1;
        ans_y[piece] = W - w[piece] + 1;

        if (h[piece] == H) {
            W -= w[piece];
        } else {
            H -= h[piece];
        }
    }

    for (int i = 0; i < N; i++) {
        cout << ans_x[i] << ' ' << ans_y[i] << '\n';
    }

    return 0;
}
