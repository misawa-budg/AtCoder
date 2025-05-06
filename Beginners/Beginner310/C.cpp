#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    string S;

    set<string> st;
    for (int i = 0; i < N; i++) {
        cin >> S;
        auto T = S;
        reverse(T.begin(), T.end());
        st.insert(min(S, T));
    }
    cout << st.size() << endl;

    return 0;
}
