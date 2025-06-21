#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;
    vector<char> isBlack(N + 2, false);

    long long ans = 0;
    for (int i = 0; i < Q; i++) {
        int A; cin >> A;
        bool cur = isBlack[A];
        bool front = isBlack[A - 1], back = isBlack[A + 1];
        if (cur) {
            ans += -1 + front + back;
        } else {
            ans += 1 - front - back;
        }
        isBlack[A] = !isBlack[A];
        cout << ans << endl;
    }

    return 0;
}
