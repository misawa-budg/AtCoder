#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<string> S(N); for (int i = 0; i < N; i++) cin >> S[i];
    int target; cin >> target;
    string Y; cin >> Y;

    if (S[target - 1] == Y) cout << "Yes" << '\n';
    else cout << "No" << '\n';

    return 0;
}
