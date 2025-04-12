#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int scoreSum = 0, score;
    for (int i = 0; i < 9; i++) {
        cin >> score;
        scoreSum += score;
    }
    for (int i = 0; i < 8; i++) {
        cin >> score;
        scoreSum -= score;
    }

    cout << scoreSum + 1 << endl;

    return 0;
}
