#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;

    for (int x = 0; x <= N; x++) {
        for (int y = 0; y <= N; y++) {
            if (x + y > N) break;
            for (int z = 0; z <= N - x - y; z++) {
                cout << x << " " << y << " " << z << endl;
            }
        }
    }

    return 0;
}
