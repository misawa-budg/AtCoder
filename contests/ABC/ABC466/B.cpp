#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int N, M; cin >> N >> M;
    vector<set<int, greater<>>> sizeByColor(M + 1);

    for (int i = 0; i < N; i++) {
        int color, size;
        cin >> color >> size;

        sizeByColor[color].insert(size);
    }

    for (int i = 1; i <= M; i++) {
        if (sizeByColor[i].size() != 0) {
            cout << *(sizeByColor[i].begin()) << ' ';
        } else {
            cout << -1 << ' ';
        }
    }
    cout << '\n';

    return 0;
}
