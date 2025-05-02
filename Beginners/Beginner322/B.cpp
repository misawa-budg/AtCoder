#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; cin >> N >> M;
    string S, T; cin >> S >> T;

    size_t prefixIndex = T.find(S);
    size_t suffixIndex = T.rfind(S);
    if (prefixIndex == 0 && suffixIndex == T.size() - S.size()) {
        cout << 0 << endl;
    } else if (prefixIndex == 0 && suffixIndex != T.size() - S.size()) {
        cout << 1 << endl;
    } else if (prefixIndex != 0 && suffixIndex == T.size() - S.size()) {
        cout << 2 << endl;
    } else if (prefixIndex != 0 && suffixIndex != T.size() - S.size()) {
        cout << 3 << endl;
    }

    return 0;
}
