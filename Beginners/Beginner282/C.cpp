#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    string S; cin >> S;

    int inDelimiter = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == '"') {
            inDelimiter = !inDelimiter;
        } else if (!inDelimiter && S[i] == ',') {
            S[i] = '.';
        }
    }

    cout << S << endl;

    return 0;
}
