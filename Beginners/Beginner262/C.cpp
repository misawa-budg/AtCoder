#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> A(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> A[i];
    }

    long long ans = 0;

    long long cnt = 0;
    for (int i = 1; i <= N; i++) {
        if (A[i] == i) {
            cnt++;
        }
    }
    ans += cnt * (cnt - 1) / 2;

    long long cnt2 = 0;
    for (int i = 1; i <= N; i++) {
        int j = A[i];
        if (i < j) {
            if (A[j] == i) {
                cnt2++;
            }
        }
    }
    ans += cnt2;

    cout << ans << '\n';


    return 0;
}
