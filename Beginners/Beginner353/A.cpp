#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    int target;
    for (int i = 0; i < N; i++) {
        if (!i) cin >> target;
        else {
            int building;
            cin >> building;
            if (building > target) {
                cout << i + 1 << endl;
                return 0;
            }
        }
    }

    cout << -1 << endl;

    return 0;
}
