#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;
    char world = S[0], stage = S[2];

    if (stage == '8') {
        world++;
        stage = '1';
    } else {
        stage++;
    }
    cout << world << '-' << stage << '\n';

    return 0;
}
