#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;

    vector<int> divisors;
    for (int i = 1; i <= 9; i++) {
        if (N % i == 0) {
            divisors.push_back(i);
        }
    }

    cout << "1";
    for (int i = 1; i <= N; i++) {
        bool found = false;
        for (int divisor : divisors) {
            if (i % (N / divisor) == 0) {
                found = true;
                cout << divisor;
                break;
            }
        }
        if (!found) cout << "-";
    }
    cout << endl;

    return 0;
}
