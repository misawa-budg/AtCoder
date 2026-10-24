#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    map<string, int> bank;
    int newId = 1;

    int Q; cin >> Q;
    while (Q--) {
        string S; cin >> S;

        if (bank.contains(S)) {
            cout << bank[S] << '\n';
        } else {
            bank[S] = newId;
            cout << newId++ << '\n';
        }
    }

    return 0;
}
