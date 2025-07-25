#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    string S; cin >> S;

    bool ok = true;
    for (int i = 1; i < N; i++) {
        if (S[i] == S[i - 1]) {
            ok = false;
            break;
        }
    }
    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
