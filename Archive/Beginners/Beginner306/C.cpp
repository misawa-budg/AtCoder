#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> counter(N + 1, 0);
    vector<int> ans;
    vector<int> A(3 * N);
    for (int i = 0; i < 3 * N; i++) {
        int input; cin >> input;
        counter[input]++;
        if (counter[input] == 2) {
            ans.push_back(input);
        }
    };


    for (int i = 0; i < N; i++) {
        if (i) cout << " ";
        cout << ans[i];
    }
    cout << endl;



    return 0;
}
