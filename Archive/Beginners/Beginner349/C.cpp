#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S; cin >> S;
    string T; cin >> T;

    bool isIncluded = true;
    for (char &c : T) {
        if (isupper(c)) {
            c = tolower(c);
        }
    }

    size_t pos = 0;
    for (int i = 0; i < T.size(); i++) {
        char letter = T[i];
        if (i == 2 && letter == 'x') break;
        else if (S.find(letter, pos) == string::npos) {
            isIncluded = false;
            break;
        } else {
            pos = S.find(letter, pos) + 1;
        }
    }

    if (isIncluded) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
