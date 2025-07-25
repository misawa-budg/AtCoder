#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> A(64);
    for (int i = 0; i < 64; i++) {
        cin >> A[i];
    }

    unsigned long long ans = 0;
    for (int i = 0; i < 64; i++) {
        ans += A[i] * (1ULL << i);
    }
    cout << ans << endl;

    return 0;
}
