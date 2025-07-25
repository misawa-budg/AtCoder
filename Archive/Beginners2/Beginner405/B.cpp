#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];

    vector<bool> has(M + 1, false);
    for (int i = 0; i <= N; i++) {
        fill(has.begin(), has.end(), false);
        for (int j = 0; j < N - i; j++) {
            has[A[j]] = true;
        }
        for (int j = 1; j <= M; j++) {
            if (!has[j]) {
                cout << i << endl;
                return 0;
            }
        }
    }

    return 0;
}
