#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N, T, P;
    scanf("%d %d %d", &N, &T, &P);
    int *L = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++) {
        scanf("%d", &L[i]);
    }

    int days = 0;
    while(days < 100) {
        int count = 0;
        for(int i = 0; i < N; i++) {
            if(L[i] >= T) count++;
        }
        if(count >= P) break;
        days++;
        for(int i = 0; i < N; i++) {
            L[i] += 1;
        }
    }

    printf("%d\n", days);

    free(L);

    return 0;
}
