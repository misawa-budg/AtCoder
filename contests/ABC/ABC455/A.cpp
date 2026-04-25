#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int A, B, C; cin >> A >> B >> C;

    cout << ((A != B && B == C) ? "Yes\n" : "No\n");

    return 0;
}
