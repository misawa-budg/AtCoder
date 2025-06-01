#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<string> S(N); for (int i = 0; i < N; i++) cin >> S[i];

    set<string> unique_names;
    for (int i = 0; i < N; i++) {
        if (unique_names.count(S[i]) == 0) {
            cout << i + 1 << endl;
        }
        unique_names.insert(S[i]);
    }

    return 0;
}
