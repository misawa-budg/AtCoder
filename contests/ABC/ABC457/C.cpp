#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, K; cin >> N >> K;
    vector<vector<long long>> A(N);
    
    for (int i = 0; i < N; i++) {
        int L; cin >> L;
        for (int j = 0; j < L; j++) {
            int num; cin >> num;
            A[i].push_back(num);
        }
    }

    vector<long long> C(N); for (int i = 0; i < N; i++) cin >> C[i];

    for (int i = 0; i < N; i++) {
        long long size = A[i].size();
        long long total = size * C[i];

        if (K <= total) {
            cout << A[i][(K - 1) % size] << '\n';
            return 0;
        } else {
            K -= total;
        }
    }

    return 0;
}
