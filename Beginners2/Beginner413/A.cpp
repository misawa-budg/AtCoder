#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];

    for (int i = 0; i < N; i++) {
        M -= A[i];
        if (M < 0) {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";

    return 0;
}
