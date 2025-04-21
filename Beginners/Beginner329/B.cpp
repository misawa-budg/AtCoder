#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N);
    int max = 0;
    for (int i = 0; i < N; i++) {
        cin >> A[i];
        if (A[i] > max) {
            max = A[i];
        }
    }

    sort(A.begin(), A.end());
    int index = lower_bound(A.begin(), A.end(), max) - A.begin() - 1;

    cout << A[index] << endl;

    return 0;
}
