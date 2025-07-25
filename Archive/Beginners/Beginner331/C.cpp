#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<long long> origin(N);
    for (int i = 0; i < N; i++) cin >> origin[i];
    vector<long long> A = origin;
    sort(A.begin(), A.end());

    vector<long long> cumulativeSum(N);
    cumulativeSum[0] = A[0];
    for (int i = 1; i < N; i++) cumulativeSum[i] = cumulativeSum[i - 1] + A[i];

    for (int i = 0; i < N; i++) {
        long long target = origin[i];
        int index = upper_bound(A.begin(), A.end(), target) - A.begin();

        if (index > N - 1) {
            cout << 0 << " ";
        } else {
            cout << cumulativeSum[N - 1] - cumulativeSum[index - 1] << " ";
        }
    }
    cout << endl;

    return 0;
}
