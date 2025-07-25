#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<string> S(N); for (int i = 0; i < N; ++i) cin >> S[i];

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) continue;
            string concat = S[i] + S[j];
            bool is_palindrome = true;
            for (int k = 0; k < concat.size() / 2; ++k) {
                if (concat[k] != concat[concat.size() - 1 - k]) {
                    is_palindrome = false;
                    break;
                }
            }
            if (is_palindrome) {
                cout << "Yes" << endl;
                return 0;
            }
        }
    }
    cout << "No" << endl;

    return 0;
}
