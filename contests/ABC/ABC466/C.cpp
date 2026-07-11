#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    int ans = 0;
    int r = 1;

    for (int l = 1; l < N; l++) {
        r = max(r, l);

        while (r < N) {
            cout << "? " << l << " " << r + 1 << endl;
            string res; cin >> res;
            if (res == "Yes") r++;
            else break;
        }

        ans += (r - l);
    }

    cout << "! " << ans << endl;

    return 0;
}
