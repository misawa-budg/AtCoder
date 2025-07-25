#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;
    for (int i = 0; i < S.size()/2; i++) {
        swap(S[2*i], S[2*i+1]);
    }
    cout << S << endl;

    return 0;
}
