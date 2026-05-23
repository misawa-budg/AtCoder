#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<string> S(N); for (int i = 0; i < N; i++) cin >> S[i];

    for (int i = 0; i < N; i++) {
        char target = S[i][0];

        if ('a' <= target && target <= 'c') cout << 2;
        else if ('d' <= target && target <= 'f') cout<< 3;
        else if ('g' <= target && target <= 'i') cout << 4;
        else if ('j' <= target && target <= 'l') cout << 5;
        else if ('m' <= target && target <= 'o') cout << 6;
        else if ('p' <= target && target <= 's') cout << 7;
        else if ('t' <= target && target <= 'v') cout << 8;
        else if ('w' <= target && target <= 'z') cout << 9;
    }

    cout << '\n';

    return 0;
}
