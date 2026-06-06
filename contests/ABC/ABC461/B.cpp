#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    for (int i = 0; i < N; i++) cin >> B[i];

    for (int i = 0; i < N; i++) {
        if (B[A[i] - 1] != i + 1) {
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";

    return 0;
}
