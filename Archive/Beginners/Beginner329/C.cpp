#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    string S; cin >> S;
    vector<int> letterContinuous(26, 0);

    int count = 1;
    char prev = S[0];
    for (int i = 1; i < N; i++) {
        if (S[i] == prev) {
            count++;
        } else {
            letterContinuous[prev - 'a'] = max(letterContinuous[prev - 'a'], count);
            count = 1;
            prev = S[i];
        }
    }
    letterContinuous[prev - 'a'] = max(letterContinuous[prev - 'a'], count);

    long long ans = 0;
    for (int i = 0; i < 26; i++) {
        ans += letterContinuous[i];
    }

    cout << ans << endl;

    return 0;
}
