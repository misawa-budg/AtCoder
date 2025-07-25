#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    string S; cin >> S;

    for (int i = 0; i < N - 1; i++) {
        int ans = 0;
        while (i + ans < N - 1 && S[ans] != S[ans + i + 1]) ans++;
        cout << ans << endl;
    }


    return 0;
}
