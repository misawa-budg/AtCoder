#include <bits/stdc++.h>
using namespace std;

long long X, Y;

long long solve(long long a)
{
    if (a == 1) return X;
    else if (a == 2) return Y;
    else {
        string s = to_string(solve(a - 1) + solve(a - 2));
        string s_rev = s;
        reverse(s_rev.begin(), s_rev.end());
        return stoll(s_rev);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> X >> Y;
    long long ans = solve(10);
    cout << ans << endl;

    return 0;
}
