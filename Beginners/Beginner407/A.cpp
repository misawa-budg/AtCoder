#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    float A, B; cin >> A >> B;
    int ans = floor(A / B + 0.5);
    cout << ans << endl;

    return 0;
}
