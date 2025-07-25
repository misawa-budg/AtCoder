#include <stdio.h>
#include <stdlib.h>

#define MAX_M 200005

int main() {
    int N, M;
    scanf("%d %d", &N, &M);

    int *max_Li = (int*)calloc(M + 2, sizeof(int));
    if (max_Li == NULL) {
        fprintf(stderr, "メモリ確保に失敗しました。\n");
        return 1;
    }

    for(int i = 0; i < N; i++) {
        int Li, Ri;
        scanf("%d %d", &Li, &Ri);
        if(Li > max_Li[Ri]) {
            max_Li[Ri] = Li;
        }
    }

    for(int r = 1; r <= M; r++) {
        if(max_Li[r] < max_Li[r - 1]) {
            max_Li[r] = max_Li[r - 1];
        }
    }

    long long forbidden = 0;
    for(int r = 1; r <= M; r++) {
        forbidden += max_Li[r];
    }

    long long total = ((long long)M * (M + 1)) / 2;
    long long answer = total - forbidden;

    printf("%lld\n", answer);

    free(max_Li);

    return 0;
}
