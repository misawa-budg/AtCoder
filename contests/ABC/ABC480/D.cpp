#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;
    vector<long long> A(N + 1); for (int i = 1; i <= N; i++) cin >> A[i];

    vector<long long> sumA(N + 1, 0), sumB(N + 1, 0), len(N + 1, 0);

    for (int i = 1; i <= N; i++) {
        sumA[i] = sumA[i - 1] + A[i];
        len[i] = len[i - 1] + i;
        sumB[i] = sumB[i - 1] + sumA[i];
    }

    auto calc = [&](long long x) -> long long {
        if (x == 0) return 0;
        int k = lower_bound(len.begin(), len.end(), x) - len.begin();
        long long rest = x - len[k - 1];
        return sumB[k - 1] + sumA[rest];
    };

    for (int i = 0; i < Q; i++) {
        long long L, R;
        cin >> L >> R;

        cout << calc(R) - calc(L - 1) << '\n';
    }


    return 0;
}
