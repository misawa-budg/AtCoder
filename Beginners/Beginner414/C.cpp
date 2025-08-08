#include <bits/stdc++.h>
using namespace std;

string convertToBaseA(const string& s, int A)
{
    long long num = stoll(s);
    string result;
    while (num > 0) {
        int remainder = num % A;
        result += remainder + '0';
        num /= A;
    }
    reverse(result.begin(), result.end());
    return (result.empty() ? "0" : result);
}

bool isPalindrome(const string& s)
{
    int n = s.size();
    for (int i = 0; i < n / 2; i++) {
        if (s[i] != s[n - 1 - i]) return false;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A; cin >> A;
    long long N; cin >> N;

    long long ans = 0;
    for (long long i = 1; i <= N; i++) {
        string orig = to_string(i);
        string cp = orig;
        reverse(cp.begin(), cp.end());

        string ev = orig + cp;
        if (stoll(ev) <= N) {
            string evBaseA = convertToBaseA(ev, A);
            if (isPalindrome(evBaseA)) ans+= stoll(ev);
        }

        string odd = orig + cp.substr(1);
        if (stoll(odd) <= N) {
            string oddBaseA = convertToBaseA(odd, A);
            if (isPalindrome(oddBaseA)) ans+= stoll(odd);
        } else {
            break;
        }
    }
    cout << ans << '\n';

    return 0;
}
