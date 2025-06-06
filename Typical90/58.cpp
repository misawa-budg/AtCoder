#include <bits/stdc++.h>
using namespace std;

int sumDigits(long long n)
{
    int sum = 0;
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long N, K; cin >> N >> K;
    const int MOD = 100000;

    vector<long long> visited(MOD, -1);
    vector<long long> history;

    long long cur = N;
    long long step = 0;
    while (visited[cur] == -1 && step < K) {
        visited[cur] = step;
        history.push_back(cur);
        cur = (cur + sumDigits(cur)) % MOD;
        step++;
    }

    if (step == K) {
        cout << cur << endl;
    } else {
        long long cycleStart = visited[cur];
        long long cycleLength = step - cycleStart;

        long long remainSteps = K - cycleStart;
        long long positionInCycle = remainSteps % cycleLength;
        long long result = history[cycleStart + positionInCycle];
        cout << result << endl;
    }

    return 0;
}
