#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    string S; cin >> S;

    for (int i = 0; i < N - 1; i++) {
        if (S[i] == 'a' && S[i + 1] == 'b') {
            cout << "Yes" << endl;
            return 0;
        }
        if (S[i] == 'b' && S[i + 1] == 'a') {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}
