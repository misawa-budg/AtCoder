#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N; string S; cin >> S;

    set<char> st = {'A', 'B', 'C'};
    int ans = 0;
    for (int i = 0; i <= N; i++) {
        if (st.size() > 0) {
            st.erase(S[i]);
        } else {
            ans = i;
            break;
        }
    }
    cout << ans << endl;

    return 0;
}
