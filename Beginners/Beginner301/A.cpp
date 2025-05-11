#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    string S; cin >> S;

    int aoki = 0, takahashi = 0;
    for (int i = 0; i < N; ++i) {
        if (S[i] == 'A') {
            aoki++;
        } else {
            takahashi++;
        }
    }

    if (aoki > takahashi) {
        cout << "A" << endl;
    } else if (aoki < takahashi) {
        cout << "T" << endl;
    } else {
        cout << (S[N - 1] == 'A' ? "T" : "A") << endl;
    }

    return 0;
}
