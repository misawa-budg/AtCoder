#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;
    vector<string> v = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    auto saturday_idx = find(v.begin(), v.end(), "Saturday") - v.begin();
    auto today_idx    = find(v.begin(), v.end(), S) - v.begin();
    cout << saturday_idx - today_idx << '\n';

    return 0;
}
