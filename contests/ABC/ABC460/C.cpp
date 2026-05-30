#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<long long> A(N), B(M);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int j = 0; j < M; j++) cin >> B[j];

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    int count = 0;

    int j = 0;
    for (int i = 0; i < N; i++) {
        if (j >= M) break;

        if (B[j] <= A[i] * 2) {
            j++;
            count++;
        }
    }

    cout << count << '\n';

    return 0;
}
