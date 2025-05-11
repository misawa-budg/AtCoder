#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S, T; cin >> S >> T;

    set<char> atcoder;
    for (char c : "atcoder") atcoder.insert(c);

    int s_at_count = count(S.begin(), S.end(), '@');
    int t_at_count = count(T.begin(), T.end(), '@');

    bool ok = true;
    for (char c = 'a'; c <= 'z'; c++) {
        int s_count = count(S.begin(), S.end(), c);
        int t_count = count(T.begin(), T.end(), c);
        if (s_count != t_count && !atcoder.count(c)) {
            ok = false;
            break;
        }

        if (s_count > t_count) {
            t_at_count -= s_count - t_count;
        } else {
            s_at_count -= t_count - s_count;
        }
    }
    if (s_at_count < 0 || t_at_count < 0) {
        ok = false;
    }

    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
