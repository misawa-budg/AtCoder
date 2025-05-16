#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<string> S(N); for (int i = 0; i < N; ++i) cin >> S[i];

    int count = 0;
    for (int i = 0; i < N; i++) {
        if (S[i] == "For") {
            count++;
        }
        if (count > N / 2) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;

    return 0;
}
