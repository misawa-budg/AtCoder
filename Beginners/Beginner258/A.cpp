#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int K; cin >> K;
    int minutes = 21 * 60 + K;
    int hours = minutes / 60;
    int mins = minutes % 60;

    cout << setfill('0') << setw(2) << hours << ":"
         << setfill('0') << setw(2) << mins << "\n";

    return 0;
}
