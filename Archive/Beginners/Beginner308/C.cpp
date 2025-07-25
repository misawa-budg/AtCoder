#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<tuple<int, int, int>> coinTosses(N);
    for (int i = 0; i < N; ++i) {
        int heads, tails; cin >> heads >> tails;
        coinTosses[i] = make_tuple(heads, tails, i);
    }

    sort(coinTosses.begin(), coinTosses.end(), [](const auto& a, const auto& b) {
        __int128_t aHeads = get<0>(a); __int128_t aTails = get<1>(a);
        __int128_t bHeads = get<0>(b); __int128_t bTails = get<1>(b);

        __int128_t left = aHeads * (bHeads + bTails);
        __int128_t right = bHeads * (aHeads + aTails);
        if (left != right) {
            return left > right;
        } else {
            return get<2>(a) < get<2>(b);
        }
    });

    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << get<2>(coinTosses[i]) + 1;
    }
    cout << endl;

    return 0;
}
