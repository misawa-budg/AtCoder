#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    string S; cin >> S;
    int len = S.size();
    while (len < N) {
        cout << 'o';
        len++;
    }
    cout << S << '\n';

    return 0;
}
