#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N; cin >> N;
    string S; cin >> S;

    long long total = N * (N + 1) / 2;

    long long bad = 0;
    for (long long i = 0; i < N;) {
        long long j = i;
        while (j < N && S[j] == S[i]) {
            j++;
        }
        long long len = j - i;
        bad += len * (len + 1) / 2;
        i = j;
    }

    long long good = total - bad;
    cout << good << endl;

    return 0;
}
