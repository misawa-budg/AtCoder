#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; string S; cin >> N >> S;

    int idx = 0;
    while (S[idx] == 'o') idx++;
    for (int i = idx; i < S.length(); i++) cout << S[i];
    cout << '\n';

    return 0;
}
