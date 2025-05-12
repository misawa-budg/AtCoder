#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    string S; cin >> S;
    int start = S.find('|'), end = S.rfind('|');
    if (S.substr(start + 1, end - start - 1).find('*') == string::npos) {
        cout << "out" << endl;
    } else {
        cout << "in" << endl;
    }

    return 0;
}
