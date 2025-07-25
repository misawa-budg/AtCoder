#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    string S; cin >> S;
    string T; cin >> T;

    int ans = 0;

    for (int i = 0; i < N; i++) {
        if (S[i] != T[i]) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
