#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N); for (int i = 0; i < N; i++) cin >> A[i];

    int reach = A[0] - 1;
    int res = 1;
    for (int i = 1; i < N; i++) {
        if (reach < i) break;
        res++;
        reach = max(reach, i + A[i] - 1);
    }
    cout << res << '\n';

    return 0;
}
