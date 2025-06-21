#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;
    vector<long long> A(N); for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    vector<long long> cumulative(N + 1, 0);
    for (int i = 0; i < N; i++) cumulative[i + 1] = cumulative[i] + A[i];

    for (int i = 0; i < Q; i++) {
        long long target; cin >> target;
        int border = upper_bound(A.begin(), A.end(), target) - A.begin();

        long long under = (border * target) - cumulative[border];
        long long over = (cumulative[N] - cumulative[border]) - ((N - border) * target);
        long long result = under + over;
        cout << result << '\n';
    }

    return 0;
}
