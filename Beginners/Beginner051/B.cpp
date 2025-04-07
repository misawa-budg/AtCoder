#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K, S;
    cin >> K >> S;

    int ans = 0;
    for (int x = 0; x <= K; x++) {
        for (int y = 0; y <= K; y++) {
            int z = S - x - y;
            if (z >= 0 && z <= K) ans++;
        }
    }

    cout << ans << endl;

    return 0;
}
