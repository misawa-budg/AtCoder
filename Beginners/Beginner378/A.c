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
    int A[4];
    int used[4] = {0};
    int count = 0;
    for (int i = 0; i < 4; i++) {
        scanf("%d", &A[i]);
    }

    int color;
    for (int i = 0; i < 3; i++) {
        if (used[i] == 0) {
            color = A[i];
            for (int j = i + 1; j < 4; j++) {
                if (color == A[j] && used[j] == 0) {
                    count++;
                    used[i] = used[j] = 1;
                    break;
                }
            }
        }
    }

    printf("%d\n", count);

    return 0;
}
