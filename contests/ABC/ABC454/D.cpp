#include <bits/stdc++.h>
using namespace std;

string parseStr(string S) {
    string ans;
    for (char c : S) {
        ans += c;

        int size = ans.length();
        if (ans[size-1]==')' && ans[size-4]=='('
         && ans[size-3]=='x' && ans[size-2]=='x') {
            for (int i = 0; i < 4; i++) ans.pop_back();
            ans += "xx";
         }
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        string A, B; cin >> A >> B;
        string parsedA = parseStr(A);
        string parsedB = parseStr(B);

        if (parsedA == parsedB) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
