#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;

    if (S.size() < 3) {
        cout << 0 << endl;
        return 0;
    }

    int count = 0;
    double ans = 0.0;
    for (int i = 0; i < S.size() - 1; i++) {
        for (int j = i + 1; j < S.size(); j++) {
            int len = j - i + 1;
            if (len < 3) continue;
            if (S[i] != 't' || S[j] != 't') continue;

            int count = 0;
            for (int k = i; k <= j; k++) {
                if (S[k] == 't') count++;
            }

            ans = max(ans, static_cast<double>(count - 2) / (len - 2));
        }
    }

    cout << fixed << setprecision(12) << ans << endl;

    return 0;
}
