#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<string> W(N); for (int i = 0; i < N; i++) cin >> W[i];
    set<string> S = {"and", "not", "that", "the", "you"};

    for (int i = 0; i < N; i++) {
        if (S.count(W[i])) {
            cout << "Yes\n";
            return 0;
        }
    }
    cout << "No\n";

    return 0;
}
