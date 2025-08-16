#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;

    map<string, string> mp;
    mp["red"] = "SSS";
    mp["blue"] = "FFF";
    mp["green"] = "MMM";

    if (mp.find(S) != mp.end()) {
        cout << mp[S] << endl;
    } else {
        cout << "Unknown" << endl;
    }

    return 0;
}
