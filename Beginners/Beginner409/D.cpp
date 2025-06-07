#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        int N; string S; cin >> N >> S;

        int start = -1;
        for (int i = 0; i < N - 1; i++) {
            if (S[i] > S[i + 1]) {
                start = i;
                break;
            }
        }
        if (start == -1) {
            cout << S << endl;
            continue;
        }

        char target = S[start];
        string T = S.substr(start + 1);
        int end = 1;
        for (end; end < T.size(); end++) {
            if (T[end] > target) {
                break;
            }
        }

        string result = S.substr(0, start) + T.substr(0, end);
        result += target + T.substr(end);
        cout << result << endl;
    }

    return 0;
}
