#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N;
    scanf("%d", &N);

    int A[N+1][N+1];
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= i; j++) {
            scanf("%d", &A[i][j]);
        }
    }

    int genso = 1;

    for(int i = 1; i <= N; i++) {
        if(genso >= i) {
            genso = A[genso][i];
        } else {
            genso = A[i][genso];
        }
    }
    printf("%d\n", genso);

    return 0;

}
