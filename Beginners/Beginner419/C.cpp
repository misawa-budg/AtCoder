#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    long long mxr, mxc;
    long long mnr, mnc;
    mxr = mxc = LLONG_MIN;
    mnr = mnc = LLONG_MAX;

    for (int i = 0; i < N; i++) {
        long long r, c; cin >> r >> c;
        mxr = max(mxr, r);
        mxc = max(mxc, c);
        mnr = min(mnr, r);
        mnc = min(mnc, c);
    }

    cout << (max(abs(mxr - mnr), abs(mxc - mnc)) + 1) / 2 << endl;



    return 0;
}
