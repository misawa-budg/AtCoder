#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    string S; cin >> S;
    int shirtCount = M, logoCount = 0, logoMax = 0;
    int ans = 0;

    for (int i = 0; i < N; i++) {
        if (S[i] == '0') {
            shirtCount = M;
            logoCount = logoMax;
        } else if (S[i] == '1') {
            if (shirtCount > 0) shirtCount--;
            else logoCount--;
        } else if (S[i] == '2') {
            logoCount--;
        }

        if (shirtCount < 0) {
            ans++;
            shirtCount = 0;
        }
        if (logoCount < 0) {
            ans++;
            logoMax++;
            logoCount = 0;
        }
    }

    cout << ans << endl;

    return 0;
}
