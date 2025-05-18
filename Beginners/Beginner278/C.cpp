#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;
    set<pair<int, int>> S;

    for (int i = 0; i < Q; i++) {
        int T, A, B; cin >> T >> A >> B;
        A--; B--;

        if (T == 1) {
            S.insert({A, B});
        } else if (T == 2) {
            S.erase({A, B});
        } else if (T == 3) {
            if (S.count({A, B}) && S.count({B, A})) {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}
