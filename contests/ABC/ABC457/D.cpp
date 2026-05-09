#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, K; cin >> N >> K;
    vector<long long> A(N); for (int i = 0; i < N; i++) cin >> A[i];

    long long ok = 0;
    long long ng = A[0] + K + 1;

    while (ng - ok > 1) {
        long long mid = ok + (ng - ok) / 2;
        long long need = 0;

        for (int i = 0; i < N; i++) {
            if (A[i] < mid) {
                long long diff = mid - A[i];
                long long add = i + 1;

                need += (diff + add - 1) / add;

                if (need > K) break;
            }
        }

        if (need <= K) ok = mid;
        else ng = mid;
    }

    cout << ok << '\n';

    return 0;
}
