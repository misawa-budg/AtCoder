#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string N; cin >> N;

    for (int i = 0; i < N.size(); i++) {
        if (i <= 2) {
            cout << N[i];
        } else {
            cout << "0";
        }
    }
    cout << endl;

    return 0;
}
