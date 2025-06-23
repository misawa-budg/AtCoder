#include <bits/stdc++.h>
using namespace std;

long long power(long long base, long long exp)
{
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) result *= base;
        base *= base;
        exp /= 2;
    }
    return result;
}

long long count_snake_numbers(const string& S)
{
    int n = S.size();
    if (n < 2) return 0;

    vector<int> digits;
    for (char c : S) digits.push_back(c - '0');

    long long ans = 0;

    for (int digit = 2; digit < n; digit++) {
        for (int head = 1; head <= 9; head++) {
            ans += power(head, digit - 1);
        }
    }

    int limit = digits[0];
    for (int head = 1; head < limit; head++) {
        ans += power(head, n - 1);
    }

    bool valid = true;
    for (int i = 1; i < n; i++) {
        int digitLimit = digits[i];

        for (int digit = 0; digit < digitLimit; digit++) {
            if (digit < limit) {
                int remain = n - 1 - i;
                ans += power(limit, remain);
            }
        }

        if (digitLimit >= limit) {
            valid = false;
            break;
        }
    }
    if (valid) {
        ans++;
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long L, R; cin >> L >> R;

    string SL = to_string(L-1), SR = to_string(R);

    long long ans = count_snake_numbers(SR) - count_snake_numbers(SL);
    cout << ans << '\n';

    return 0;
}
