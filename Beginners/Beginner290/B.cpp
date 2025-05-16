#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K; cin >> N >> K;
    string S; cin >> S;
    string T = "";

    int remain = K;
    for (int i = 0; i < N; i++) {
        if (S[i] == 'o') {
            if (remain > 0) {
                T += 'o';
                remain--;
            } else {
                T += 'x';
            }
        } else {
            T += 'x';
        }
    }
    cout << T << endl;

    return 0;
}
