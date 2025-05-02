#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    string S; cin >> S;

    int ans = S.find("ABC");
    if (ans == string::npos) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans + 1 << endl;

    return 0;
}
