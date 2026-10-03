#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; cin >> N >> K;
    vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];
    vector<int> B = A;
    sort(B.begin(), B.end());

    int left = N, right = -1;
    for (int i = 0; i < N; i++) {
        if (A[i] != B[i]) {
            left = min(left, i);
            right = max(right, i);
        }
    }

    if (left == N) {
        cout << "Yes\n";
        return 0;
    }

    if (right - left + 1<= K) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
