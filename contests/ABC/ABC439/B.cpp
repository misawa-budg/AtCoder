#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string N; cin >> N;
    bool isHappy = false;
    set<int> seen;

    while (true) {
        int total = 0;
        for (int i = 0; i < N.length(); i++) {
            int target = N[i] - '0';
            total += target * target;
        }

        if (total == 1) {
            isHappy = true;
            break;
        }

        if (seen.contains(total)) break;

        seen.insert(total);
        N = to_string(total);
    }

    cout << ((isHappy) ? "Yes\n" : "No\n");

    return 0;
}
