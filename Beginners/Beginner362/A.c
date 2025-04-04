#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int R, G, B;
    char C[10];

    scanf("%d %d %d", &R, &G, &B);
    scanf("%s", C);

    int min_cost;
    if (strcmp(C, "Red") == 0) {
        min_cost = (G < B) ? G : B;
    } else if (strcmp(C, "Green") == 0) {
        min_cost = (R < B) ? R : B;
    } else if (strcmp(C, "Blue") == 0) {
        min_cost = (R < G) ? R : G;
    }

    printf("%d\n", min_cost);

    return 0;
}
