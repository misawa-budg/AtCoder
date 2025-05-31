#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    set<int> A;
    for (int i = 0; i < N; ++i) {
        int a; cin >> a;
        A.insert(a);
    }

    cout << A.size() << endl;
    for (const auto& a : A) {
        cout << a << ' ';
    } cout << endl;


    return 0;
}
