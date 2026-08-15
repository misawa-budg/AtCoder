#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    set<long long> s;
    for (int i = 0; i < N; i++) {
        long long input; cin >> input;
        s.insert(input);
    }

    long long cur = 0, ans = 0;

    while (!s.empty()) {
        auto it = s.lower_bound(cur);
        long long next;

        if (it == s.begin()) next = *it;
        else if (it == s.end()) next = *prev(it);
        else {
            long long right = *it, left = *prev(it);

            long long dl = cur - left, dr = right - cur;

            if (dl <= dr) next = left;
            else next = right;
        }

        ans += abs(next - cur);
        cur = next;
        s.erase(next);
    }

    cout << ans << '\n';

    return 0;
}
