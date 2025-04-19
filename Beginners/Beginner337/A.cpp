#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    int scoreT = 0, scoreA = 0;

    for (int i = 0; i < N; i++) {
        int t, a; cin >> t >> a;
        scoreT += t;
        scoreA += a;
    }

    if (scoreT == scoreA) {
        cout << "Draw" << endl;
    } else if (scoreT > scoreA) {
        cout << "Takahashi" << endl;
    } else {
        cout << "Aoki" << endl;
    }

    return 0;
}
