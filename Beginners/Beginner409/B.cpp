#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];

    sort(A.begin(), A.end(), greater<int>());
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (A[i] >= i + 1) ans = i + 1;
        else break;
    }
    cout << ans << endl;

    return 0;
}
