#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;

    int letterCount[26] = {0};
    for (char c : S) {
        letterCount[c - 'a']++;
    }

    int occurrencesArray[101] = {0};
    for (int i = 0; i < 26; i++) {
        if (letterCount[i] > 0)
            occurrencesArray[letterCount[i]]++;
    }

    bool isGoodString = true;
    for (int i = 0; i < 101; i++) {
        if (occurrencesArray[i] != 0 && occurrencesArray[i] != 2) {
            isGoodString = false;
            break;
        }
    }

    if (isGoodString) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
