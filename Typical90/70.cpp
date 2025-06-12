#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<long long> X(N), Y(N);
    for (int i = 0; i < N; ++i) {
        cin >> X[i] >> Y[i];
    }
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    long long medianX = X[(N-1) / 2];
    long long medianY = Y[(N-1) / 2];

    long long totalDistance = 0;
    for (int i = 0; i < N; ++i) {
        totalDistance += abs(X[i] - medianX) + abs(Y[i] - medianY);
    }
    cout << totalDistance << '\n';

    return 0;
}
