#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    long long length = 0;

    string ans;
    for (int i = 0; i < N; i++) {
        char c;
        long long l;
        cin >> c >> l;

        length += l;
        if (length > 100) {
            cout << "Too Long\n";
            return 0;
        }

        for (int j = 0; j < l; j++) ans += c;
    }
    cout << ans << '\n';

    return 0;
}
