#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        long long N, M; cin >> N >> M;
        vector<long long> A(N), B(N);
        long long sumA = 0, sumB = 0;
        for (auto &x : A) { cin >> x; sumA += x; }
        for (auto &x : B) { cin >> x; sumB += x; }

        vector<long long> need(N);
        for (int i = 0; i < N; ++i)
            need[i] = (B[i] == 0 ? M : M - B[i]);

        sort(A.begin(), A.end());
        sort(need.begin(), need.end());

        long long k = 0;
        int i = 0, j = 0;
        while (i < N && j < N) {
            if (A[i] >= need[j]) { ++k; ++i; ++j; }
            else ++i;
        }

        cout << (sumA + sumB - k * M) << '\n';
    }

    return 0;
}
