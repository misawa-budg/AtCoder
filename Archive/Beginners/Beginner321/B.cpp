#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X; cin >> N >> X;
    vector<int> A(N - 1); for (int i = 0; i < N - 1; i++) cin >> A[i];

    for (int i = 0; i <= 100; i++) {
        int minNum = LLONG_MAX;
        int maxNum = INT_MIN;
        int sum = 0;
        vector<int> B = A;
        B.push_back(i);
        for (int j = 0; j < N; j++) {
            minNum = min(minNum, B[j]);
            maxNum = max(maxNum, B[j]);
            sum += B[j];
        }
        sum -= minNum; sum -= maxNum;

        if (sum >= X) {
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;

    return 0;
}
