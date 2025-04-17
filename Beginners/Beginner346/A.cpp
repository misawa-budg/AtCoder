#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N);
    for (auto &x : A) cin >> x;

    for (int i = 0; i < N - 1; i++) {
        cout << A[i] * A[i + 1] << " ";
    }
    cout << endl;

    return 0;
}
