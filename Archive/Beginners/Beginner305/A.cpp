#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;

    int remain = N % 5;
    if (remain > 2) {
        cout << (N / 5 + 1) * 5 << endl;
    } else {
        cout << (N / 5) * 5 << endl;
    }

    return 0;
}
