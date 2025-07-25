#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    long long sum = 0, minSum = 0;
    for (int i = 0; i < N; i++) {
        sum += A[i];
        if (sum < minSum) {
            minSum = sum;
        }
    }

    cout << sum + -minSum << endl;

    return 0;
}
