#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<long long> A(N); 
    for (size_t i = 0; i < N; i++) cin >> A[i];

    map<long long, long long> cnt_r;
    map<long long, long long> cnt_l;
    for (int i = 0; i < N; i++) cnt_r[A[i]]++;
    
    long long total = 0;
    for (int j = 0; j < N; j++) {
        long long cur = A[j];
        // A[j]より大きいindex{A[j + n], A[j+n]のoccur}
        cnt_r[cur]--;

        if (cur % 5 == 0) {
            // 3x : 5x : 7x
            long long x = cur / 5;
            long long val7 = 7 * x;
            long long val3 = 3 * x;

            // i, k < j
            total += cnt_l[val3] * cnt_l[val7];
            // j < i, j
            total += cnt_r[val3] * cnt_r[val7];
        }

        // A[j + 1]より小さいindex{A[j], A[j]のoccur}
        cnt_l[cur]++;
    }

    cout << total << '\n';

    return 0;
}
