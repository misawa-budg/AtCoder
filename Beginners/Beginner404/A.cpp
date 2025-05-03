#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;
    set <char> st;
    for (char c : S) {
        st.insert(c);
    }

    for (char c = 'a'; c <= 'z'; c++) {
        if (st.find(c) == st.end()) {
            cout << c << '\n';
            return 0;
        }
    }

    return 0;
}
