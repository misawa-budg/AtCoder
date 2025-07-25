#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N; cin >> N;
    vector<string> S(N);
    int min = INT_MAX, minIndex = -1;
    for (int i = 0; i < N; i++) {
        string name; int age;
        cin >> name >> age;
        S[i] = name;
        if (age < min) {
            min = age;
            minIndex = i;
        }
    }

    for (int i = 0; i < N; i++) {
        cout << S[(minIndex + i) % N] << endl;
    }

    return 0;
}
