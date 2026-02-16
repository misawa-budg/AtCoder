#include <bits/stdc++.h>
using namespace std;

int calc(int x)
{
    int total = 0;
    string str_num = to_string(x);
    for (char& c : str_num) {
        total += (c - '0') * (c - '0');
    }

    return total;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    set<int> history;

    while (N > 1) {
        if (history.find(N) != history.end()) {
            cout << "No\n";
            return 0;
        }

        history.insert(N);
        N = calc(N);
    }
    cout << "Yes\n";

    return 0;
}
