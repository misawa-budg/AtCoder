#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; cin >> N >> K;
    vector<long long> A(N), B(N);
    for (int i = 0; i < N; i++) {
        cin >> A[i] >> B[i];
    }

    priority_queue<pair<long long, int>> q1, q2;
    for (int i = 0; i < N; i++) {
        q1.push({B[i], i});
    }

    long long ans = 0;
    for (int i = 0; i < K; i++) {
        int half = (q1.empty() ? INT_MIN : q1.top().first);
        int full = (q2.empty() ? INT_MIN : q2.top().first);

        if (half < full) {
            long long point = q2.top().first;
            ans += point;
            q2.pop();
        } else {
            long long point = q1.top().first;
            ans += point;
            int idx = q1.top().second;
            q2.push({A[idx] - B[idx], idx});
            q1.pop();
        }
    }

    cout << ans << endl;

    return 0;
}
