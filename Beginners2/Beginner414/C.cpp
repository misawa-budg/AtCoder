#include <bits/stdc++.h>
using namespace std;

string convert_to_base(long long N, int base)
{
    string result;
    while (N > 0) {
        int digit = N % base;
        result += '0' + digit;
        N /= base;
    }
    reverse(result.begin(), result.end());
    return result.empty() ? "0" : result;
}

bool is_palindrome(const string& s)
{
    int left = 0, right = s.size() - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A;
    long long N;
    cin >> A >> N;

    long long ans = 0;
    for (long long k = 1;; k++) {
        string s = to_string(k);

        string oddS = s, evenS = s;
        reverse(oddS.begin(), oddS.end());
        reverse(evenS.begin(), evenS.end());

        string oddCandidate = s + oddS.substr(1);
        long long oddNum = stoll(oddCandidate);
        if (oddNum > N) break;
        if (is_palindrome(convert_to_base(oddNum, A))) ans += oddNum;

        string evenCandidate = s + evenS;
        long long evenNum = stoll(evenCandidate);
        if (evenNum <= N) {
            if (is_palindrome(convert_to_base(evenNum, A))) ans += evenNum;
        }
    }

    cout << ans << endl;

    return 0;
}
