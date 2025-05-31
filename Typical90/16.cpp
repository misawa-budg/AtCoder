#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    int A, B, C; cin >> A >> B >> C;

    const int MAX = 10000;
    int ans = INT_MAX;
    for (int a = 0; a < MAX; a++) {
        int remainA = N - A * a;
        if (remainA < 0) break;
        for (int b = 0; a + b < MAX; b++) {
            int remain = remainA - B * b;
            if (remain < 0) break;
            if (remain % C != 0) continue;
            int c = remain / C;
            ans = min(ans, a + b + c);
        }
    }

    cout << ans << endl;

    return 0;
}
