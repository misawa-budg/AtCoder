#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int Q; cin >> Q;
    int volume = 0;
    bool isPlaying = false;
    for (int i = 1; i <= Q; i++) {
        int A; cin >> A;
        if (A == 1) {
            volume++;
        } else if (A == 2) {
            if (volume >= 1) {
                volume--;
            }
        } else if (A == 3) {
            isPlaying = !isPlaying;
        }
        if (volume >= 3 && isPlaying) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
    }

    return 0;
}
