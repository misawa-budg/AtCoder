#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;

    long long total = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == 'C') {
            total += min((int)S.size() - (i+1), i) + 1;
        }
    }

    cout << total << '\n';

    return 0;
}
