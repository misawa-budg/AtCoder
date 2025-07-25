#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<long long> L(N); for(int i=0;i<N;i++) cin >> L[i], L[i]++;

    long long left = *max_element(L.begin(), L.end()) - 1;
    long long right = accumulate(L.begin(), L.end(), 0LL);

    while (left + 1 < right) {
        long long mid = (left + right) / 2;

        long long length = 0, rows = 1;
        for (int i = 0; i < N; i++) {
            length += L[i];

            if (length > mid) {
                rows++;
                length = L[i];
            }
        }

        if (rows > M) {
            left = mid;
        } else {
            right = mid;
        }
    }
    cout << right - 1 << endl;

    return 0;
}
