#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int X; cin >> X;

    string S = "HelloWorld";
    for (int i = 0; i < S.size(); i++) {
        if (i + 1 == X) continue;
        cout << S[i];
    }
    cout << '\n';

    return 0;
}
