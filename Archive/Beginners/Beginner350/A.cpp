#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;

    if (S.substr(0, 3) != "ABC") {
        cout << "No" << endl;
        return 0;
    }

    int n = atoi(S.substr(S.size()-3).c_str());
    if ((1 <= n && n <= 315) || (317 <= n && n <= 349)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
