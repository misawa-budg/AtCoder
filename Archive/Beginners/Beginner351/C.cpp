#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    deque<long long> A;
    for (int i = 0; i < N; ++i) {
        int input;
        cin >> input;
        A.push_back(input);

        while (true) {
            if (A.size() <= 1) break;

            int first = A.back(); A.pop_back();
            int second = A.back(); A.pop_back();

            if (first != second) {
                A.push_back(second);
                A.push_back(first);
                break;
            } else {
                long long ball = first + 1;
                A.push_back(ball);
            }
        }
    }

    cout << A.size() << endl;

    return 0;
}
