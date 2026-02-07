#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string N; cin >> N;

    if (N[0] == N[1] && N[1] == N[2]) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
    }

    return 0;
}
