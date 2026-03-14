#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    const double pi = 3.14159265358979;

    double D; cin >> D; D /= 2;
    cout << fixed << setprecision(15) << D * D * pi << '\n';

    return 0;
}
