#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    int X; cin >> X;
    for (int i = 0; i < N; i++) {
        if (A[i] == X) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";

    return 0;
}
