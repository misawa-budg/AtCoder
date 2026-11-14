#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K; cin >> K;

    bool hasNine = false;
    int minBall = 10;

    for (int i = 0; i < K; i++) {
        int ball; cin >> ball;
        if (ball == 9) hasNine = true;
        minBall = min(minBall, ball);
    }

    if (!hasNine) {
        cout << -1 << '\n';
    } else {
        cout << minBall <<'\n';
    }

    return 0;
}
