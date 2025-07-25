#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<int> A(M); for (int i = 0; i < M; ++i) cin >> A[i];

    for (int i = 1; i <= N; i++) {
        int day = lower_bound(A.begin(), A.end(), i) - A.begin();

        cout << A[day] - i << endl;
    }

    return 0;
}
