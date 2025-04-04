#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N, K;
    scanf("%d %d", &N, &K);
    int *A=(int *)malloc(N * sizeof(int));
    int *temp=(int *)malloc(N * sizeof(int));

    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        temp[i] = A[i];
    }

    for(int i = 0; i < N; i++) {
        A[(i + K) % N] = temp[i];
    }

    for(int i = 0; i < N; i++) {
        if(i) printf(" ");
        printf("%d", A[i]);
    }

    return 0;

}
