#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, T; cin >> N >> T;
    vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];

    long long sum = accumulate(A.begin(), A.end(), 0LL);
    T %= sum;

    for (int i = 0; i < N; i++) {
        T -= A[i];
        if (T < 0) {
            cout << i + 1 << " " << A[i] + T << endl;
            break;
        }
    }

    return 0;
}
