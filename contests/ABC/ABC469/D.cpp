#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;

    vector<int> A(M), B(M);

    for (int i = 0; i < M; i++) {
        cin >> A[i] >> B[i];
    }

    auto check = [&](int x, int y) {
        for (int i = 0; i < M; i++) {
            if (A[i] != x && B[i] != x &&
                A[i] != y && B[i] != y) {
                return false;
            }
        }

        return true;
    };

    auto calc = [&](int x) {
        int a = -1;
        int b = -1;

        for (int i = 0; i < M; i++) {
            if (A[i] != x && B[i] != x) {
                a = A[i];
                b = B[i];
                break;
            }
        }

        if (a == -1) {
            return (long long)N - 1;
        }

        long long cnt = 0;

        if (check(x, a)) cnt++;
        if (check(x, b)) cnt++;

        return cnt;
    };

    int x = A[0];
    int y = B[0];

    long long ans = calc(x) + calc(y);

    if (check(x, y)) ans--;

    cout << ans << '\n';

    return 0;
}
