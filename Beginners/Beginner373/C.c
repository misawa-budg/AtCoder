#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);
    int A[N], B[N];

    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
    }
    for(int i = 0; i < N; i++) {
        scanf("%d", &B[i]);
    }

    int Amax = A[0], Bmax = B[0];

    for(int i = 0; i < N; i++) {
        if(Amax < A[i]) Amax = A[i];
        if(Bmax < B[i]) Bmax = B[i];
    }

    printf("%d\n", Amax + Bmax);

    return 0;
}
