#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L, R;
    cin >> N >> L >> R;
    vector<int> A(N);
    for (int i = 1; i <= N; i++) {
        A[i - 1] = i;
    }
    reverse(A.begin() + L - 1, A.begin() + R);

    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << A[i];
    }
    cout << endl;

    return 0;
}
