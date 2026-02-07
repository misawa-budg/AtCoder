#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    string S, T; cin >> S >> T;

    int Q; cin >> Q;
    for (int i = 0; i < Q; i++) {
        string target; cin >> target;

        bool found = false;
        for (int j = 0; j < target.length(); j++) {
            if (S.contains(target[j]) && T.contains(target[j])) {
                continue;
            } else if (S.contains(target[j])) {
                found = true;
                cout << "Takahashi\n";
            } else if (T.contains(target[j])) {
                found = true;
                cout << "Aoki\n";
            }
            if (found) break;
        }
        if (!found) cout << "Unknown\n";
    }

    return 0;
}
