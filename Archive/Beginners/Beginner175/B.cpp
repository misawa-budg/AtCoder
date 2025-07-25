#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> L(N);
    for (int i = 0; i < N; i++) cin >> L[i];
    sort(L.begin(), L.end());

    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (L[i] == L[j]) continue;
            for (int k = j + 1; k < N; k++) {
                if (L[k] == L[i] || L[k] == L[j]) continue;
                if (L[i] + L[j] > L[k]) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}
