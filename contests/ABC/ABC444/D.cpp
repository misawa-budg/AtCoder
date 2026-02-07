#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N; cin >> N;
    vector<int> A(N);
    int biggest = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        biggest = max(biggest, A[i]);
    }

    vector<long long> frequency(biggest + 1, 0), cumulative(biggest + 2, 0);
    for (int x : A) frequency[x]++;

    for (int len = biggest; len >= 1; len--) {
        cumulative[len] = cumulative[len + 1] + frequency[len];
    }

    vector<int> digits;
    long long carry = 0;

    for (int len = 1; len <= biggest; len++) {
        long long cur = cumulative[len] + carry;
        digits.push_back((int)(cur % 10));
        carry = cur / 10;
    }

    while (carry > 0) {
        digits.push_back((int)(carry % 10));
        carry /= 10;
    }

    for (int i = (int)digits.size() - 1; i >= 0; i--) cout << digits[i];
    cout << '\n';
    return 0;
}
