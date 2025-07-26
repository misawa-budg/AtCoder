#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L, R; cin >> N >> L >> R;
    string S; cin >> S;
    for (int i = L - 1; i < R; i++) {
        if (S[i] != 'o') {
            cout << "No\n";
            return 0;
        }
    }
    cout << "Yes\n";

    return 0;
}
