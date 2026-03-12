#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    
    int result = 0;
    for (int i = 1; i <= N; i++) {
        result += i;
    }
    cout << result << '\n';

    return 0;
}
