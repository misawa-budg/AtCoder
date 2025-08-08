#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L, R; cin >> N >> L >> R;
    int count = 0;
    for (int i = 0; i < N; i++) {
        int X, Y; cin >> X >> Y;
        if (X <= L && R <= Y) count++;
    }

    cout << count << '\n';

    return 0;
}
