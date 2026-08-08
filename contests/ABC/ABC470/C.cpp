#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, Q; cin >> N >> Q;
    vector<int> A(N, 0);
    set<int> active;
    
    int ans = 0;
    while (Q--) {
        int query; cin >> query;

        if (query == 1) {
            int x; cin >> x; x--;
            ans ^= A[x];
            if (A[x] == 0) active.insert(x);
            ans ^= ++A[x];
        } else {
            for (auto it = active.begin(); it != active.end(); ) {
                ans ^= A[*it];
                ans ^= --A[*it];
                if (A[*it] == 0) it = active.erase(it);
                else it++;
            }
        }
        cout << ans << '\n';
    }
    

    return 0;
}
