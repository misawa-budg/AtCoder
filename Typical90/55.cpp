#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, P, Q; cin >> N >> P >> Q;
    vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];

    long long ans = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            for (int k = j + 1; k < N; k++) {
                for (int l = k + 1; l < N; l++) {
                    for (int m = l + 1; m < N; m++) {
                        long long tmp = A[i];
                        tmp = (tmp * A[j]) % P;
                        tmp = (tmp * A[k]) % P;
                        tmp = (tmp * A[l]) % P;
                        tmp = (tmp * A[m]) % P;
                        if (tmp == Q) ans++;
                    }
                }
            }
        }
    }

    cout << ans << endl;

    return 0;
}
