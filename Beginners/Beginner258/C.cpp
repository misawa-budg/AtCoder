#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;
    string S; cin >> S;

    int offset = 0;
    for (int i = 0; i < Q; i++) {
        int query, x; cin >> query >> x;
        if (query == 1) {
            offset = (offset + x) % N;
        } else if (query == 2) {
            x--;
            int index = (x - offset + N) % N;
            cout << S[index] << "\n";
        }
    }

    return 0;
}
