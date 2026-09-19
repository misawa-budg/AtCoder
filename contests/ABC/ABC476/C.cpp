#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<long long> A(N); for (int i = 0; i < N; i++) cin >> A[i];

    vector<long long> tops = {A[0], A[1], A[2]};
    sort(tops.rbegin(), tops.rend());

    cout << tops[2] << '\n';

    for (int i = 3; i < N; i++) {
        if (A[i] > tops[0]) {
            tops[2] = tops[1];
            tops[1] = tops[0];
            tops[0] = A[i];
        } else if (A[i] > tops[1]) {
            tops[2] = tops[1];
            tops[1] = A[i];
        } else if (A[i] > tops[2]) {
            tops[2] = A[i];
        }
        cout << tops[2] << '\n';
    }

    return 0;
}
