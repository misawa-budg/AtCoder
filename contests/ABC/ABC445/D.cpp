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

    vector<int> h_ord(N), w_ord(N);
    iota(h_ord.begin(), h_ord.end(), 0);
    sort(h_ord.begin(), h_ord.end(), [&](int x, int y) { return h[x] > h[y]; });
    iota(w_ord.begin(), w_ord.end(), 0);
    sort(w_ord.begin(), w_ord.end(), [&](int x, int y) { return w[x] > w[y]; });

    vector<int> ans_h(N), ans_w(N);
    vector<bool> used(N);
    auto ith = h_ord.begin();
    auto itw = w_ord.begin();
    for (int rem = N - 1; rem >= 0; rem--) {
        while (used[*ith]) ith++;
        while (used[*itw]) itw++;

        int idx = (h[*ith] == H) ? *ith : *itw;

        used[idx] = true;
        ans_h[idx] = H - h[idx] + 1;
        ans_w[idx] = W - w[idx] + 1;

        if (h[idx] == H) {
            W -= w[idx];
        } else {
            H -= h[idx];
        }
    }

    for (int i = 0; i < N; i++) {
        cout << ans_h[i] << ' ' << ans_w[i] << '\n';
    }
    
    return 0;
}
