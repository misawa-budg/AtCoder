#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<int> H(N); for (int i = 0; i < N; ++i) cin >> H[i];

    cout << max_element(H.begin(), H.end()) - H.begin() + 1 << endl;

    return 0;
}
