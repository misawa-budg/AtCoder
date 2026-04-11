#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    string S; cin >> S;

    string ans = "";
    bool first = true;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'o' && first) continue;
        else {
            ans += S[i];
            first = false;
        }
    }
    cout << ans << '\n';

    return 0;
}
