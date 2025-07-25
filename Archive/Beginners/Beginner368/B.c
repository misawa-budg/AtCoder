#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);

    int *A = (int *)malloc(N * sizeof(int));

    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int temp, count = 0;
    int remain = N;

    while (remain > 1) {
        for(int i = 0; i < N; i++) {
            for(int j = i + 1; j < N; j++) {
                if(A[i] < A[j]) {
                    temp = A[i];
                    A[i] = A[j];
                    A[j] = temp;
                }
            }
        }
        A[0]--; A[1]--;
        if(A[0] == 0) remain--;
        if(A[1] == 0) remain--;
        count++;
    }

    printf("%d\n", count);

    free(A);

    return 0;

}
