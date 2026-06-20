#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    char X; cin >> X;
    vector<bool> hasEmpty(5, false);

    for (int i = 0; i < N; i++) {
        string seats; cin >> seats;
        for (int j = 0; j < 5; j++) {
            if (seats[j] == 'o') hasEmpty[j] = true;
        }
    }

    if (hasEmpty[X - 'A']) cout << "Yes\n";
    else cout << "No\n";

    return 0;
}
