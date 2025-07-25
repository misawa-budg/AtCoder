#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    set<string> seen;
    int maxPoint = -1;
    int idx = -1;
    for (int i = 0; i < N; i++) {
        string S; cin >> S;
        int point; cin >> point;
        if (!seen.count(S)) {
            seen.insert(S);

            if (point > maxPoint) {
                maxPoint = point;
                idx = i + 1;
            }
        }
    }

    cout << idx << endl;

    return 0;
}
