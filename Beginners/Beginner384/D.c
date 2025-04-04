#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

int checkSubSum(long long A[], int N, long long X) {
    int left = 0;
    long long current_sum = 0;
    for (int right = 0; right < N; right++) {
        current_sum += A[right];
        while (current_sum > X && left <= right) {
            current_sum -= A[left++];
        }
        if (current_sum == X) return 1;
    }
    return 0;
}

int main() {
    int N;
    long long S;
    scanf("%d %lld", &N, &S);

    long long *A = (long long*)malloc(sizeof(long long)*N);
    for (int i = 0; i < N; i++) {
        scanf("%lld", &A[i]);
    }

    long long T = 0;
    for (int i = 0; i < N; i++) {
        T += A[i];
    }

   long long target;
    if (S <= T) {
        target = S;
    } else {
        long long R = S % T;
        target = (R == 0) ? T : R;
    }

    if (checkSubSum(A, N, target)) {
        printf("Yes\n");
        free(A);
        return 0;
    }

    long long *A2 = (long long*)malloc(sizeof(long long)*2*N);
    for (int i = 0; i < N; i++) {
        A2[i] = A[i];
        A2[i+N] = A[i];
    }

    if (checkSubSum(A2, 2*N, target)) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    free(A);
    free(A2);
    return 0;
}
