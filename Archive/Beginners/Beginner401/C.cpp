#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; cin >> N >> K;

    if (N < K) {
        cout << 1 << endl;
        return 0;
    }
    vector<long long> A(N+1, 0);
    for (int i = 0; i < K; i++) {
        A[i] = 1;
    }
    long long sectionSum = K;
    for (int i = K; i < N+1; i++) {
        if (sectionSum > 1e9) {
            A[i] = sectionSum % 1000000000;
        } else {
            A[i] = sectionSum;
        }
        sectionSum += A[i];
        sectionSum -= A[i - K];
    }

    cout << A[N] % 1000000000 << endl;

    return 0;
}
