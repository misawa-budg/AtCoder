#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, P, Q; cin >> N >> P >> Q;
    vector<int> D(N); for (int i = 0; i < N; ++i) cin >> D[i];

    int minimum = *min_element(D.begin(), D.end());

    cout << min(minimum + Q, P) << endl;

    return 0;
}
