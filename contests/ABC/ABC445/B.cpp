#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<string> S(N);
    int biggest = 0;
    for (int i = 0; i < N; i++) {
        cin >> S[i];
        int length = S[i].size();
        biggest = max(length, biggest);
    }

    for (int i = 0; i < N; i++) {
        int length = S[i].size();
        if (length != biggest) {
            int count = (biggest - length) / 2;
            for (int j = 0; j < count; j++) cout << '.';
            cout << S[i];
            for (int j = 0; j < count; j++) cout << '.';
        } else {
            cout << S[i];
        }
        cout << '\n';
    }

    return 0;
}
