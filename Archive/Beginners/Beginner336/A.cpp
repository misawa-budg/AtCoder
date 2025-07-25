#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    string ans;
    ans += "L";
    for (int i = 0; i < N; i++) {
        ans += "o";
    }
    ans += "ng";

    cout << ans << endl;

    return 0;
}
