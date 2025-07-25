#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, A, B; cin >> N >> A >> B;
    string S; cin >> S; S += S;

    long long ans = LLONG_MAX;
    for (int ACount = 0; ACount < N; ACount++) {
        long long tmp = A * ACount;
        for (int i = 0; i < N / 2; i++) {
            int l = ACount + i;
            int r = ACount + N - i - 1;
            if (S[l] != S[r]) tmp += B;
        }
        ans = min(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}
