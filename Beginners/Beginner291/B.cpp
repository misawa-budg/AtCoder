#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> X(5 * N); for (int i = 0; i < 5 * N; i++) cin >> X[i];
    sort(X.begin(), X.end());

    vector<int> Y(X.begin() + N, X.end() - N);
    int sum = accumulate(Y.begin(), Y.end(), 0);
    cout << fixed << setprecision(10) << (double)sum / (3 * N) << endl;

    return 0;
}
