#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b; double d; cin >> a >> b >> d;

    double rad = d * M_PI / 180.0;
    double x = a*cos(rad) - b*sin(rad);
    double y = a*sin(rad) + b*cos(rad);

    cout << fixed << setprecision(10) << x << " " << y << "\n";

    return 0;
}
