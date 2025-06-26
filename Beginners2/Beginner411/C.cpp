#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;
    vector<int> A(Q); for (int i = 0; i < Q; i++) cin >> A[i];

    int ans = 0;
    vector<char> isBlack(N + 2, 0);
    for (int i = 0; i < Q; i++) {
        int target = A[i];
        char left = isBlack[target - 1], right = isBlack[target + 1];
        if (isBlack[target]) ans += -1 + left + right;
        else ans += 1 - left - right;
        isBlack[target] = !isBlack[target];
        cout << ans << '\n';
    }

    return 0;
}
