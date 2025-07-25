#include <bits/stdc++.h>
using namespace std;

bool firstCheck(string s)
{
    return s[0]=='H' || s[0]=='D' || s[0]=='C' || s[0]=='S';
}

bool secondCheck(string s)
{
    return s[1]=='A' || s[1]=='2' || s[1]=='3' || s[1]=='4' || s[1]=='5' || s[1]=='6' || s[1]=='7' || s[1]=='8' || s[1]=='9' || s[1]=='T' || s[1]=='J' || s[1]=='Q' || s[1]=='K';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    set<string> S;
    bool ok = true;
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        if (!firstCheck(s) || !secondCheck(s)) {
            ok = false;
            break;
        }
        S.insert(s);
    }

    if (S.size() != N) {
        ok = false;
    }

    if (ok) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


    return 0;
}
