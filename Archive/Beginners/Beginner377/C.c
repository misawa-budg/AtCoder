#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int x, y;
} Position;

int compare_positions(const void* a, const void* b) {
    Position* pa = (Position*)a;
    Position* pb = (Position*)b;
    if (pa->x != pb->x) {
        return (pa->x > pb->x) - (pa->x < pb->x);
    } else {
        return (pa->y > pb->y) - (pa->y < pb->y);
    }
}

int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    Position attackedPosition[9 * M];
    int dx[9] = {2, 1, -1, -2, -2, -1, 1, 2, 0};
    int dy[9] = {1, 2, 2, 1, -1, -2, -2, -1, 0};
    int attackedCount = 0;

    for (int i = 0; i < M; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        a--; b--;
        for (int k = 0; k < 9; k++) {
            int ni = a + dx[k];
            int nj = b + dy[k];
            if (ni >= 0 && ni <= N-1 && nj >= 0 && nj <= N-1) {
                attackedPosition[attackedCount].x = ni;
                attackedPosition[attackedCount].y = nj;
                attackedCount++;
            }
        }
    }

    qsort(attackedPosition, attackedCount, sizeof(Position), compare_positions);

    long long unique_attacked = 0;
    for (int i = 0; i < attackedCount; i++) {
        if (i == 0 || attackedPosition[i].x != attackedPosition[i - 1].x || attackedPosition[i].y != attackedPosition[i - 1].y) {
            unique_attacked++;
        }
    }

    long long totalCells = (long long)N * N;
    printf("%lld\n", totalCells - unique_attacked);

    return 0;
}
