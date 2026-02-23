#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N, D; cin >> N >> D;
        vector<int> A(N), B(N);
        for (int i = 0; i < N; i++) cin >> A[i];
        for (int i = 0; i < N; i++) cin >> B[i];

        queue<int> q;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < A[i]; j++) q.push(i);
            for (int j = 0; j < B[i]; j++) q.pop();
            while (!q.empty() && i - q.front() >= D) q.pop();
        }
        
        cout << q.size() << '\n';
    }

    return 0;
}
