#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;
    map<char, int> counter;
    for (char c : S) counter[c]++;

    long long N = S.size();
    long long ans = N * N;
    bool canMakeSame = false;
    for (int i = 0; i < 26; i++) {
        long long count = counter['a' + i];
        if (count > 1) canMakeSame = true;
        ans -= count * count;
    }
    ans /= 2;
    if (canMakeSame) ans++;
    cout << ans << endl;


    return 0;
}
