#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N, K, X;

    scanf("%d %d %d", &N, &K, &X);

    int A[N], B[N+1];
    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }

    int j = 0, i = 0;
    while (j <= N) {
        if (j == K) {
            B[j] = X;
            j++;
        }
        else {
            B[j] = A[i];
            j++; i++;
        }
    }

    for(int i = 0; i <= N; i++) {
        if(i) printf(" ");
        printf("%d", B[i]);
    }
    printf("\n");

    return 0;
}
