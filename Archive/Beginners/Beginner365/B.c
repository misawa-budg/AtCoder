#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int num;
    int index;
}list;

int main() {
    list lists[2] = {0};
    int N;
    scanf("%d", &N);

    int *A = (int *)malloc(N * sizeof(int));

    lists[1].num = -1;
    for(int i = 0; i < N; i++) {
        scanf("%d", &A[i]);
        if(A[i] > lists[0].num) {
            lists[1].num = lists[0].num;
            lists[1].index = lists[0].index;
            lists[0].num = A[i];
            lists[0].index = i;
        } else if(lists[0].num > A[i] && A[i] > lists[1].num) {
            lists[1].num = A[i];
            lists[1].index = i;
        }
    }

    printf("%d\n", lists[1].index + 1);

    return 0;
}
