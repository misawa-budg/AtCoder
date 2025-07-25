#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A, B;
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        if (input % 2 == 0) {
            A.push_back(input);
        } else {
            B.push_back(input);
        }
    }

    sort(A.begin(), A.end(), greater<int>());
    sort(B.begin(), B.end(), greater<int>());

    int ans = -1;
    if (A.size() >= 2) {
        ans = max(ans, A[0] + A[1]);
    }
    if (B.size() >= 2) {
        ans = max(ans, B[0] + B[1]);
    }

    cout << ans << endl;

    return 0;
}
