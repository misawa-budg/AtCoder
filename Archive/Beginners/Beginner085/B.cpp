#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    vector<int> mochi(N);
    for (int i = 0; i < N; i++) {
        cin >> mochi[i];
    }

    sort(mochi.rbegin(), mochi.rend());

    int mochiCount = 1;
    for (int i = 1; i < N; i++) {
        if (mochi[i - 1] > mochi[i]) mochiCount++;
    }

    cout << mochiCount << endl;

    return 0;
}


// setを用いても同様の結果が得られる
// #include <bits/stdc++.h>
// using namespace std;
//
// int main()
// {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//
//     int N;
//     cin >> N;
//
//     set<int> mochiSet;
//     for (int i = 0; i < N; i++) {
//      int mochi;
//      cin >> mochi;
//      mochiSet.insert(mochi);
//     }
//
//     cout << mochiSet.size() << endl;
//
//     return 0;
// }
