#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    string S; cin >> S;

    if (S.size() < 3) {
        cout << "No" << endl;
        return 0;
    }
    string tea = S.substr(S.size() - 3);

    (tea == "tea") ? cout << "Yes" : cout << "No";
    cout << endl;

    return 0;
}
