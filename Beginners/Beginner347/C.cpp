#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, A, B;
    cin >> N >> A >> B;
    set<int> D;
    for (int i = 0; i < N; i++) {
        int input;
        cin >> input;
        D.insert(input % (A + B));
    }

    vector<int> D2;
    for (auto it = D.begin(); it != D.end(); it++) {
        D2.push_back(*it);
    }

    for (int i = 0; i < D2.size(); i++) {
        int diff;
        if (i == D2.size() - 1) diff = D2[0] + A + B - D2[i];
        else diff = D2[i + 1] - D2[i];
        if (diff > B) {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;



    return 0;
}
