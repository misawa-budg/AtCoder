#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_N 20

int main() {
    int N;
    scanf("%d", &N);

    int K[MAX_N];
    long long totalSum = 0;
    for(int i = 0; i < N; i++) {
        scanf("%d", &K[i]);
        totalSum += K[i];
    }

    long long min_max_sum = totalSum;

    for(int bit = 0; bit < (1 << N); bit++) {
        long long sum_A = 0;
        for(int i = 0; i < N; i++) {
            if(bit & (1 << i)) {
                sum_A += K[i];
            }
        }
        long long sum_B = totalSum - sum_A;
        long long current_max = sum_A > sum_B ? sum_A : sum_B;
        if(current_max < min_max_sum) {
            min_max_sum = current_max;
        }
    }

    printf("%lld\n", min_max_sum);

    return 0;
}
