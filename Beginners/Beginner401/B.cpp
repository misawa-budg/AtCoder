#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;

    int isLoggedIn = 0;
    int errorCount = 0;
    for (int i = 0; i < N; i++) {
        string input;
        cin >> input;
        if (input == "login") {
            isLoggedIn = 1;
        } else if (input == "logout") {
            isLoggedIn = 0;
        } else if (input == "private") {
            if (!isLoggedIn) errorCount++;
        }
    }

    cout << errorCount << endl;

    return 0;
}
