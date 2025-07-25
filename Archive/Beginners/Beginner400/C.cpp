#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N;
    cin >> N;

    long long ans = 0;
    long long maxA = log2(N);
    for (long long b = 1; maxA > 0; b+=2) {
        while(maxA > 0 && (1LL << maxA) * b * b > N) maxA--;
        ans += maxA;
    }

    cout << ans << endl;

    return 0;
}

// cout << (long long)sqrtl(N / 4) + (long long)sqrtl(N / 2) << endl;
