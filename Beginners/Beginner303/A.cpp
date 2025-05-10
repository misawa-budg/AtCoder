#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    string S, T; cin >> S >> T;

    bool ok = true;
    for (int i = 0; i < N; i++) {
        if (   S[i] == T[i]
            || S[i] == '1' && T[i] == 'l'
            || S[i] == 'l' && T[i] == '1'
            || S[i] == '0' && T[i] == 'o'
            || S[i] == 'o' && T[i] == '0'
        ) {}
        else {
            ok = false;
            break;
        }
    }
    cout << (ok ? "Yes" : "No") << endl;

    return 0;
}
