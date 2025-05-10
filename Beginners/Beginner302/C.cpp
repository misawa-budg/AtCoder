#include <bits/stdc++.h>
using namespace std;

int countDiff(const string &a, const string &b)
{
    int cnt = 0;
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) cnt++;
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    vector<string> S(N); for (int i = 0; i < N; i++) cin >> S[i];
    sort(S.begin(), S.end());

    do {
        bool ok = true;
        for (int i = 0; i < N - 1; i++) {
            if (countDiff(S[i], S[i + 1]) != 1) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cout << "Yes" << endl;
            return 0;
        }
    } while (next_permutation(S.begin(), S.end()));
    cout << "No" << endl;

    return 0;
}
