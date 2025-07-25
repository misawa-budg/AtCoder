#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<string> S(10);
    for (int i = 0; i < 10; i++) cin >> S[i];

    for (int h = 0; h < 10; h++) {
        for (int w = 0; w < 10; w++) {
            if (S[h][w] == '#') {
                cout << h + 1 << ' ';
                while (h + 1 < 10 && S[h + 1][w] == '#') h++;
                cout << h + 1 << endl;
                cout << w + 1 << ' ';
                while (w + 1 < 10 && S[h][w + 1] == '#') w++;
                cout << w + 1 << endl;
                return 0;
            }
        }
    }

    return 0;
}
