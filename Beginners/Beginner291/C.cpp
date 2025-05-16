#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    string S; cin >> S;
    set<pair<int, int>> st;

    auto here = make_pair(0, 0);
    st.insert(here);
    for (int i = 0; i < N; i++) {
        char dir = S[i];
        if (dir=='R') here.first++;
        else if (dir=='L') here.first--;
        else if (dir=='U') here.second++;
        else if (dir=='D') here.second--;

        if (st.count(here)) {
            cout << "Yes" << endl;
            return 0;
        }
        st.insert(here);
    }
    cout << "No" << endl;


    return 0;
}
