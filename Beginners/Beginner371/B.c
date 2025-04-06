#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int N, M;
    scanf("%d %d", &N, &M);
    int *hasBoy = (int *)malloc(sizeof(int) * N);
    for(int i = 0; i < N; i++) {
        hasBoy[i] = 0;
    }

    for(int i = 0; i < M; i++) {
        int index;
        char se;
        scanf("%d %c", &index, &se);
        index--;
        if(se == 'M') {
            if(hasBoy[index] == 0) {
                hasBoy[index] = 1;
                printf("Yes\n");
                continue;
            }
        }
        printf("No\n");
    }
    free(hasBoy);
    return 0;
}
