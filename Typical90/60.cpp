#include <bits/stdc++.h>
using namespace std;

vector<int> lis_length(const vector<int>& A)
{
    int N = A.size();
    vector<int> tails, res(N);
    for (size_t i = 0; i < N; i++) {
        int pos = lower_bound(tails.begin(), tails.end(), A[i]) - tails.begin();
        if (pos == tails.size()) tails.push_back(A[i]);
        else tails[pos] = A[i];
        res[i] = pos + 1;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];

    vector<int> inc = lis_length(A);
    vector<int> reverse_A = A;
    reverse(reverse_A.begin(), reverse_A.end());
    vector<int> rev = lis_length(reverse_A);
    vector<int> dec(N);
    for (int i = 0; i < N; i++) dec[i] = rev[N - 1 - i];

    int ans = 0;
    for (int i = 0; i < N; i++) {
        ans = max(ans, inc[i] + dec[i] - 1);
    }
    cout << ans << endl;

    return 0;
}
