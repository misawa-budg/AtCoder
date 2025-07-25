#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    string S; cin >> S;

    while (S.find("na") != string::npos) {
        S.replace(S.find("na"), 2, "nya");
    }

    cout << S << endl;

    return 0;
}
