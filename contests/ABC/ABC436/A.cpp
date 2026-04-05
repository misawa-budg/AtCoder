#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    string S; cin >> S;
    cout << string(N - S.length(), 'o') << S << '\n';

    return 0;
}
