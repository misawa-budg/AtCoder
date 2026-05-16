#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;
    int N; cin >> N;

    for (int i = N; i < S.size() - N; i++) {
        cout << S[i];
    }
    cout << '\n';

    return 0;
}
