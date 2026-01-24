#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;

    int count = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == 'i' || S[i] == 'j') {
            count++;
        }
    }
    cout << count << "\n";

    return 0;
}
