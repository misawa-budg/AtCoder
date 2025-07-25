#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N; cin >> N;
        vector<long long> A(2 * N);
        for (int i = 0; i < 2 * N; ++i) {
            cin >> A[i];
        }

        long long ans = 0;
        priority_queue<long long> pq;
        for (int i = 0; i < N; i++) {
            if (!i) pq.push(A[i]);
            else {
                pq.push(A[2 * i - 1]);
                pq.push(A[2 * i]);
            }

            ans += pq.top(); pq.pop();
        }

        cout << ans << '\n';
    }

    return 0;
}
