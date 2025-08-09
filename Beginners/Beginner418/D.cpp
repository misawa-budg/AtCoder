#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    string T; cin >> T;

    // 0の数が偶数の部分文字列をカウント
    long long ans = 0;
    long long count[2] = {1, 0};
    int sign = 0;

    for (char c : T) {
        if (c == '0') sign ^= 1;
        ans += count[sign];
        count[sign]++;
    }

    cout << ans << endl;

    return 0;
}
