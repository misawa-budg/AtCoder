#include <bits/stdc++.h>
#include "atcoder/modint.hpp"
using namespace std;
using mint = atcoder::static_modint<998244353>;

const int MAX = 4000001;
const int MOD = 998244353;

struct ModComb {
    vector<mint> fact, invFact;

    ModComb(int n) : fact(n + 1), invFact(n + 1) {
        fact[0] = 1;
        for (int i = 1; i <= n; i++) {
            fact[i] = fact[i - 1] * i;
        }
        invFact[n] = fact[n].inv();
        for (int i = n; i > 0; i--) {
            invFact[i - 1] = invFact[i] * i;
        }
    }

    mint combination(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n] * invFact[k] * invFact[n - k];
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long A, B, C, D; cin >> A >> B >> C >> D;
    ModComb mc(A + B + C + D);

    mint result = 0;
    for (int i = 0; i <= C; i++) {
        mint term1 = mc.combination(A + B + i, B);
        mint term2 = mc.combination(C - i + D - 1, D - 1);
        result += term1 * term2;
    }
    cout << result.val() << endl;

    return 0;
}
