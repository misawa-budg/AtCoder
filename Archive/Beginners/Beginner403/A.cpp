#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        if (i % 2 == 0) {
            sum += input;
        }
    }
    cout << sum << endl;

    return 0;
}
