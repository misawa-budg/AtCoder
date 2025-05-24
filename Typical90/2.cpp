#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;

    auto check = [&](string s) {
        int score = 0;
        for (int i = 0; i < N; i++) {
            if (s[i] == '(') {
                score++;
            } else if (s[i] == ')') {
                score--;
            }

            if (score < 0) return false;
        }

        return score == 0;
    };

    for (int bit = 1; bit < (1 << N); bit++) {
        string s;
        for (int i = N - 1; i >= 0; i--) {
            if (!(bit & (1 << i))) {
                s += '(';
            } else {
                s += ')';
            }
        }

        if (check(s)) {
            cout << s << '\n';
        }
    }

    return 0;
}
