#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    int sum = 0;
    for (int i = 0; i < N - 1; i++) {
        int point;
        cin >> point;
        sum += point;
    }

    cout << -sum << endl;

    return 0;
}
