#include <bits/stdc++.h>
using namespace std;

unordered_map<long long, long long> memo;

long long divideAndDivide(long long x)
{
    if (x == 1) {
        return memo[x] = 0;
    }

    auto it = memo.find(x);
    if (it != memo.end()) {
        return it->second;
    }

    long long left = divideAndDivide(x / 2);
    long long right = divideAndDivide((x + 1) / 2);
    return memo[x] = x + left + right;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N; cin >> N;

    long long ans = 0;
    ans = divideAndDivide(N);

    cout << ans << endl;

    return 0;
}
