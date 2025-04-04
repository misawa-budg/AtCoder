#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int result = 0, N;
    scanf("%d", &N);
    int *A = (int *)malloc(2 * N * sizeof(int));

    for(int i = 0; i < 2*N; i++) {
        scanf("%d", &A[i]);
    }

    for(int i = 0; i < 2*N - 2; i++) {
        if(A[i] == A[i+2]) result++;
    }

    printf("%d\n", result);

    free(A);
    return 0;
}
