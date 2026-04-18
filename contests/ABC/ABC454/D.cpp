#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T; cin >> T;
    while (T--) {
        string A, B; cin >> A >> B;

        vector<char> qA;
        for (char c : A) {
            qA.push_back(c);
            int n = qA.size();
            
            if (n >= 4 && qA[n-4] == '(' && qA[n-3] == 'x' && qA[n-2] == 'x' && qA[n-1] == ')') {
                qA.pop_back();
                qA.pop_back();
                qA.pop_back();
                qA.pop_back();
                
                qA.push_back('x');
                qA.push_back('x');
            }
        }

        vector<char> qB;
        for (char c : B) {
            qB.push_back(c);
            int n = qB.size();
            
            if (n >= 4 && qB[n-4] == '(' && qB[n-3] == 'x' && qB[n-2] == 'x' && qB[n-1] == ')') {
                qB.pop_back();
                qB.pop_back();
                qB.pop_back();
                qB.pop_back();
                
                qB.push_back('x');
                qB.push_back('x');
            }
        }

        if (qA == qB) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
