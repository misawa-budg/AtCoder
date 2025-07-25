#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<long long> L(N); for (int i = 0; i < N; i++) cin >> L[i], L[i]++;

    long long lower = *max_element(L.begin(), L.end()) - 1;
    long long upper = accumulate(L.begin(), L.end(), 0LL);

    while (lower + 1 < upper) {
        long long mid = (lower + upper) / 2;
        long long length = 0, rows = 1;
        for (int i = 0; i < N; i++) {
            length += L[i];
            if (length > mid) {
                rows++;
                length = L[i];
            }
        }

        if (rows > M) {
            lower = mid;
        } else {
            upper = mid;
        }
    }

    cout << upper - 1 << endl;


    return 0;
}
