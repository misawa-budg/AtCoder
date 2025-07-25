#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, L; cin >> N >> L;
    int count = 0;
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        if (input >= L) count++;
    }

    cout << count << endl;

    return 0;
}
