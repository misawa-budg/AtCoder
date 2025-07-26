#include <bits/stdc++.h>
using namespace std;



int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K, X; cin >> N >> K >> X;
    vector<string> S(N); for (int i = 0; i < N; i++) cin >> S[i];

    multiset<string> ms;

    auto recursive_for = [&](auto&& self, int k, string cur) {
        if (k == K) {
            ms.insert(cur);
            return;
        } else {
            for (int i = 0; i < N; i++) {
                self(self, k + 1, cur + S[i]);
            }
        }
    };

    recursive_for(recursive_for, 0, "");

    auto it = ms.begin();
    for (int i = 0; i < X - 1; i++) {
        it++;
    }
    cout << *it << '\n';

    return 0;
}
