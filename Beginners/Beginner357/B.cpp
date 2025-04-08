#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;

    int upperCount = 0;
    for (char c : S) {
        if (isupper(c)) {
            upperCount++;
        }
    }

    for (char &c : S) {
        if (upperCount > S.size() / 2) {
            c = toupper(c);
        } else {
            c = tolower(c);
        }
        cout << c;
    }
    cout << endl;

    return 0;
}
