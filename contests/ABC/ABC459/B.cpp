#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    
    const string mapping = "22233344455566677778889999";

    for (int i = 0; i < N; i++) {
        string s; cin >> s;

        cout << mapping[s[0] - 'a'];
    }
    
    cout << '\n';

    return 0;
}
