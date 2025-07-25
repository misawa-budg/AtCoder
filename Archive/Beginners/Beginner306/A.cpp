#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    string S; cin >> S;

    for (int i = 0; i < N; i++) {
        cout << S[i] << S[i];
    }
    cout << endl;

    return 0;
}
