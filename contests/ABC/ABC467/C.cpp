#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<long long> A(N), B(N - 1); // 0以上1以下の整数からなる
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N - 1; i++) cin >> B[i];

    long long ans = LLONG_MAX;

    long long cur = 0;
    long long left = A[0];
    for (int i = 0; i < N - 1; i++) {
        int right = A[i + 1];
        if ((left + right) % 2 != B[i]) {
            right++;
            cur++;
        }
        left = right;
    }
    ans = min(ans, cur);

    cur = 1;
    left = A[0] + 1;
    for (int i = 0; i < N - 1; i++) {
        int right = A[i + 1];
        if ((left + right) % 2 != B[i]) {
            right++;
            cur++;
        }
        left = right;
    }
    ans = min(ans, cur);

    cout << ans << '\n';

    return 0;
}
