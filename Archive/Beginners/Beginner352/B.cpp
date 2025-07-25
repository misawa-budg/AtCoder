#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S, T;
    cin >> S >> T;

    int N = T.size(), index = 0;
    for (int i = 0; i < N; i++) {
        if (S[index] == T[i]) {
            index++;
            cout << i + 1 << " ";
        }
    }
    cout << endl;

    return 0;
}
