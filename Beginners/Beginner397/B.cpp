#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    cin >> S;

    int count = 0;
    for (int i = 0; i < S.size(); i++) {
        if (i % 2 == 0 && S[i] == 'o') {
            S.insert(i, "i");
            count++;
        } else if (i % 2 == 1 && S[i] == 'i') {
            S.insert(i, "o");
            count++;
        }
    }

    // char target = 'i';
    // for (char c : S) {
    //     if (c == target) {
    //         target = target == 'i' ? 'o' : 'i';
    //     } else {
    //         ++ans;
    //     }
    // }
    // if (target == 'o') ++ans;

    if (S.size() % 2 == 1) count++;

    cout << count << endl;

    return 0;
}
