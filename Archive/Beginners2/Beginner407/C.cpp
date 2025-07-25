#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;

    long long count = 0;
    long long offset = 0;
    for (int i = S.size() - 1; i >= 0; i--) {
        int push = (S[i] - '0' - offset + 10) % 10;
        count += push;
        offset = (offset + push) % 10;
        count++;
    }
    cout << count << endl;

    return 0;
}
