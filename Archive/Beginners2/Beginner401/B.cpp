#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    int ans = 0;
    bool login = false;

    for (int i = 0; i < N; i++) {
        string com; cin >> com;
        if (com == "login") {
            login = true;
        } else if (com == "logout") {
            login = false;
        } else if (com == "private") {
            if (!login) ans++;
        }
    }
    cout << ans << endl;

    return 0;
}
