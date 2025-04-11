#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;

    set<string> users;
    int rateSum = 0;
    for (int i = 0; i < N; i++) {
        string name; int rate;
        cin >> name >> rate;

        users.insert(name);
        rateSum += rate;
    }

    int winner = (rateSum % N);
    auto it = users.begin();
    advance(it, winner);
    cout << *it << endl;

    return 0;
}
