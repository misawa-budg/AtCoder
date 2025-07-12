#include <bits/stdc++.h>
#include "atcoder/modint.hpp"
using namespace std;
using mint = atcoder::modint998244353;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N; cin >> N;

    mint n = N;

    mint t1 = (n - 1) * (n + 1);

    mint sum_b = n * (n + 1) / 2;
    mint t2 = sum_b - 1;

    mint t3 = 0;
    long long i = 2;
    while (i <= N) {
        long long k = N / i;
        long long j = N / k;
        mint cnt = j - i + 1;
        mint val = k;
        t3 += val * cnt;
        i = j + 1;
    }

    mint ans = t1 - t2 - t3;

    cout << ans.val() << endl;

    return 0;
}
