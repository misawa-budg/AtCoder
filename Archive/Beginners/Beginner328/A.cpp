#include <iostream>
using namespace std;

int main()
{
    int N, X; cin >> N >> X;
    int sum = 0;
    for (int i = 0; i < N; i++) {
        int input; cin >> input;
        if (input <= X) sum += input;
    }

    cout << sum << endl;

    return 0;
}