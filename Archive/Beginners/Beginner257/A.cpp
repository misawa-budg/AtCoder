#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, X; cin >> N >> X; X--;
    char letter = X / N + 'A';
    cout << letter << '\n';

    return 0;
}
