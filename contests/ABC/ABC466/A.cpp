#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    bool hasPositive = false;
    int X;
    for (int i = 0; i < N; i++) {
        cin >> X;
        if (X >= 0) {
            hasPositive = true;
        }
    }
    
    if (hasPositive) {
        cout << "No\n";
    } else {
        cout << "Yes\n";
    }

    return 0;
}
