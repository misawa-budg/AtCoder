#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct {
    int q, r;
} Garbage;

int main()
{
    int N;
    scanf("%d", &N);
    Garbage garbage[N];

    for (int i = 0; i < N; i++) {
        scanf("%d %d", &garbage[i].q, &garbage[i].r);
    }

    int Q, t, d;
    scanf("%d", &Q);

    for (int i = 0; i < Q; i++) {
        scanf("%d %d", &t, &d);
        t--;

        int qTemp = garbage[t].q;
        int rTemp = garbage[t].r;

        int x = d / qTemp;
        int tempResult = x * qTemp + rTemp;
        if (tempResult >= d) {
            printf("%d\n", tempResult);
        } else {
            printf("%d\n", ++x * qTemp + rTemp);
        }

    }

    return 0;

}
