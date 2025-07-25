#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    string T; cin >> T;
    vector<string> S(N); for (int i = 0; i < N; ++i) cin >> S[i];
    vector<int> ans;

    for (int i = 0; i < N; i++) {
        const string* pT = &T;
        const string* pS = &S[i];

        if (pS->size() > pT->size()) {
            swap(pT, pS);
        }

        const string& target    = *pT;
        const string& candidate = *pS;
        if (candidate.size() < target.size() - 1) continue;
        int j, k, miss = 0;
        bool ok = true;
        for (j = 0, k = 0; j < candidate.size() && k < target.size();) {
            if (candidate[j] == target[k]) {
                j++;
                k++;
            } else {
                miss++;
                k++;
                if (miss > 1) {
                    ok = false;
                    break;
                }
                if (candidate.size() == target.size()) j++;
            }
        }

        if (ok) ans.push_back(i+1);
    }

    cout << ans.size() << '\n';
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i != ans.size() - 1) cout << ' ';
    }
    cout << '\n';


    return 0;
}
