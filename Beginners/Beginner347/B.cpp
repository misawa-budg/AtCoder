#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;
    set<string> substrings;
    for (int i = 0; i < S.size(); i++) {
        int maxIndex = S.size() - 1;
        while (maxIndex >= i) {
            substrings.insert(S.substr(i, maxIndex - i + 1));
            maxIndex--;
        }
    }

    cout << substrings.size() << endl;

    return 0;
}
