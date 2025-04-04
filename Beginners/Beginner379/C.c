#include <stdio.h>
#include <stdlib.h>

typedef long long ll;

int compare(const void *a, const void *b) {
    ll val_a = *(ll *)a;
    ll val_b = *(ll *)b;
    if (val_a < val_b) return -1;
    if (val_a > val_b) return 1;
    return 0;
}

int main() {
    int Q;
    scanf("%d", &Q);

    ll *heights = (ll *)malloc(sizeof(ll) * Q);
    int plant_count = 0;
    ll delta = 0;

    for (int i = 0; i < Q; i++) {
        int op;
        scanf("%d", &op);
        if (op == 1) {
            heights[plant_count++] = -delta;
        } else if (op == 2) {
            ll T;
            scanf("%lld", &T);
            delta += T;
        } else if (op == 3) {
            ll H;
            scanf("%lld", &H);
            H -= delta;
            qsort(heights, plant_count, sizeof(ll), compare);

            int left = 0, right = plant_count;
            while (left < right) {
                int mid = (left + right) / 2;
                if (heights[mid] >= H) {
                    right = mid;
                } else {
                    left = mid + 1;
                }
            }
            int harvested = plant_count - left;
            printf("%d\n", harvested);
            plant_count = left;
        }
    }

    free(heights);
    return 0;
}
