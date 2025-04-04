#include <stdio.h>
#include <stdlib.h>


typedef long long ll;
ll sequence[12];
ll count_sequences = 0;

void count_backtrack(int pos, ll current, int N, ll M) {
    if (pos == N + 1) {
        count_sequences++;
        return;
    }

    // 次に選べる数の最小値
    ll min_val;
    if (pos == 1) {
        min_val = 1;
    } else {
        min_val = current + 10;
    }
    ll max_val = M - 10LL * (N - pos);
    if (max_val < min_val) return;

    for (ll next = min_val; next <= max_val; next++) {
        count_backtrack(pos + 1, next, N, M);
    }
}

void enumerate_backtrack(int pos, ll current, int N, ll M) {
    if (pos == N + 1) {
        for (int i = 1; i <= N; i++) {
            printf("%lld", sequence[i]);
            if (i != N) printf(" ");
        }
        printf("\n");
        return;
    }

    ll min_val;
    if (pos == 1) {
        min_val = 1;
    } else {
        min_val = current + 10;
    }
    ll max_val = M - 10LL * (N - pos);
    if (max_val < min_val) return;

    for (ll next = min_val; next <= max_val; next++) {
        sequence[pos] = next;
        enumerate_backtrack(pos + 1, next, N, M);
    }
}

int main() {
    int N;
    ll M;
    scanf("%d %lld", &N, &M);
    count_backtrack(1, 0, N, M);
    printf("%lld\n", count_sequences);

    enumerate_backtrack(1, 0, N, M);

    return 0;
}
